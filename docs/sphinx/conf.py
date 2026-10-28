# Configuration file for the Sphinx documentation builder.
#
# This file is part of the FFTLIB documentation build.
#
# Theme and CSS override approach (html_theme + theme_overrides.css) are
# deliberately mirrored from TexasInstruments/processor-sdk-doc:
#   html_theme = 'sphinx_rtd_theme'
#   html_logo  pointing at _static/img/ti_logo.png
#   html_show_sphinx = False
#   def setup(app): app.add_css_file("css/theme_overrides.css")
#
# All DEVFAMILY / OS / tag-loader machinery present in processor-sdk-doc has
# been omitted — FFTLIB is a single-target C library and does not need it.
#
# Doxygen XML is produced by the CMake build (not by Exhale).  Pass the
# output directory via the FFTLIB_DOXYGEN_XML environment variable before
# invoking sphinx-build, e.g.:
#   export FFTLIB_DOXYGEN_XML=/path/to/build/docs/xml
#   sphinx-build -b html docs/sphinx docs/sphinx/_build/html

import os
import sys

# ---------------------------------------------------------------------------
# Project information
# ---------------------------------------------------------------------------

project   = "FFTLIB"
author    = "Texas Instruments Incorporated"
copyright = "2026, Texas Instruments Incorporated"

# Show the source branch under the logo so the rendered docs correlate with
# the code they were generated from. Priority: explicit env override
# (FFTLIB_DOC_REF, set by CI) -> current git branch -> "main".
import subprocess


def _doc_ref():
    ref = os.environ.get("FFTLIB_DOC_REF")
    if ref:
        return ref.strip()
    try:
        out = subprocess.run(
            ["git", "rev-parse", "--abbrev-ref", "HEAD"],
            cwd=os.path.dirname(os.path.abspath(__file__)),
            capture_output=True, text=True, timeout=5)
        branch = out.stdout.strip()
        if branch and branch != "HEAD":
            return branch
    except Exception:
        pass
    return "main"


version = _doc_ref()
release = version

# ---------------------------------------------------------------------------
# Doxygen XML directory
# ---------------------------------------------------------------------------

_fallback_xml_dir = os.path.abspath(
    os.path.join(os.path.dirname(__file__), "..", "..", "build", "docs", "xml")
)

xml_dir = os.environ.get("FFTLIB_DOXYGEN_XML", _fallback_xml_dir)

if not os.path.isdir(xml_dir):
    import warnings
    warnings.warn(
        f"[conf.py] Doxygen XML directory not found: {xml_dir!r}\n"
        "  Set FFTLIB_DOXYGEN_XML to the path produced by the CMake 'doxygen' target, "
        "or run CMake first to generate the XML before invoking sphinx-build.",
        stacklevel=2,
    )

# ---------------------------------------------------------------------------
# Extensions
# ---------------------------------------------------------------------------

extensions = [
    "breathe",
    "sphinx.ext.mathjax",
    "sphinx_design",
    "sphinx_copybutton",
    "sphinx.ext.graphviz",
    "sphinx_immaterial",
]

# ---------------------------------------------------------------------------
# Source / master document
# ---------------------------------------------------------------------------

master_doc = "index"

# ---------------------------------------------------------------------------
# C-centric language settings
# ---------------------------------------------------------------------------

primary_domain     = "c"
highlight_language = "c"

# ---------------------------------------------------------------------------
# Breathe configuration
# ---------------------------------------------------------------------------

breathe_projects        = {"fftlib": xml_dir}
breathe_default_project = "fftlib"
# FFTLIB is C, not C++. Parse .h/.c as the C domain so typedef'd handle
# signatures resolve instead of tripping the C++ declaration parser.
breathe_domain_by_extension = {"h": "c", "c": "c"}

# ---------------------------------------------------------------------------
# API reference generation (per-kernel Doxygen groups)
# ---------------------------------------------------------------------------
# FFTLIB organizes each kernel as a Doxygen group (\defgroup / \addtogroup).
# The kernel OVERVIEW — including the LaTeX formulas embedded in the header
# comments — lives in the group's detailed description, which Exhale's
# file/function tree does not surface. Instead we emit one page per group
# using Breathe's ``.. doxygengroup::`` directive (which renders the overview
# prose + formulas + all member functions). This auto-scales to every kernel
# and is reused unchanged across the sibling libraries (dsplib, audiolib, ...).

import glob
import xml.etree.ElementTree as ET

_API_DIR = os.path.join(os.path.dirname(__file__), "api")

# Groups rendered without ``:members:`` because their header has an unbalanced
# Doxygen group (``@{`` with no ``@}``), which duplicates a member under ``-W``.
# Remove entries here once the corresponding header is fixed on Bitbucket dev.
#
# Note: duplicate-ID warnings for shared symbols (split_factor_gen_r2c,
# tw_gen_r2c, FFTLIB_FFT1D_I32FC_C32FC_O32FC_PBLOCK_SIZE) are handled at the
# Doxygen level via EXCLUDE_SYMBOLS in doxyfile_sphinx, not here.
_NO_MEMBERS_GROUPS = set()

# Ordered API grouping for the index page.  Each entry is
# (category_title, [group_stem, ...]) matching the README kernel taxonomy.
# Any group discovered in the XML but NOT listed here is emitted under a
# final "Other" toctree and triggers a build warning.
_API_GROUP_ORDER = [
    ("FFT — C7 SE/SA Kernels (fft_c7x)", [
        "FFT_C7X",
        "FFTLIB_fft1d_i16sc_c16sc_o16sc",
        "FFTLIB_fft1d_i32f_c32fc_o32fc",
        "FFTLIB_fft1d_i32fc_c32fc_o32fc",
        "FFTLIB_fft1dBatched_i16sc_c16sc_o16sc",
        "FFTLIB_fft1dBatched_i32f_c32fc_o32fc",
        "FFTLIB_fft1dBatched_i32fc_c32fc_o32fc",
        "FFTLIB_ifft1d_i32fc_c32fc_o32f",
        "FFTLIB_ifft1d_i32fc_c32fc_o32fc",
        "FFTLIB_ifft1dBatched_i32fc_c32fc_o32f",
        "FFTLIB_ifft1dBatched_i32fc_c32fc_o32fc",
    ]),
    ("FFT — C7+MMA DFT Kernels (fft_c7xmma, C7100/C7120 only)", [
        "FFTLIB_FFT",
        "FFTLIB_FFT_fft_ixX_cxX_oxX",
        "FFTLIB_FFT_dftSmall_ixX_cxX_oxX",
        "FFTLIB_FFT_dftLarge_ixX_cxX_oxX",
        "FFTLIB_FFT_highRadixDecompositions_ixX_cxX_oxX",
    ]),
    ("Linear Algebra", [
        "FFTLIB_LINALG",
        "FFTLIB_LINALG_matrixMatrixMultiply_ixX_ixX_oxX",
    ]),
    ("Common", [
        "FFTLIB_COMMON",
    ]),
]


def _caption_to_slug(caption):
    """Convert a caption like 'FFT — C7 SE/SA Kernels (fft_c7x)' to a safe slug."""
    import re
    slug = caption.lower()
    slug = re.sub(r"[^a-z0-9]+", "_", slug)
    slug = slug.strip("_")
    return slug


def _generate_api_pages(xml_directory, api_directory):
    """Emit api/index.rst + per-page RST files for all Doxygen groups.

    Layout produced (mirrors TISP immaterial pattern):
    - Per-group pages: ``api/<group>.rst`` using ``.. doxygengroup::``.
    - Landing pages per caption: ``api/<slug>.rst``
      (e.g., ``api/fft_c7_se_sa_kernels_fft_c7x_.rst``) with a toctree of
      that category's group pages.
    - ``api/index.rst``: ONE toctree (:maxdepth: 2, no :caption:) listing all
      landing pages so sphinx-immaterial renders each caption as a nav section.
    """
    if not os.path.isdir(xml_directory):
        return
    os.makedirs(api_directory, exist_ok=True)

    groups = []  # list of (group_name, title)
    for path in sorted(glob.glob(os.path.join(xml_directory, "group__*.xml"))):
        try:
            root = ET.parse(path).getroot()
        except ET.ParseError:
            continue
        compound = root.find("./compounddef[@kind='group']")
        if compound is None:
            continue
        name_el = compound.find("compoundname")
        if name_el is None or not name_el.text:
            continue
        name = name_el.text.strip()
        title_el = compound.find("title")
        title = (title_el.text.strip() if title_el is not None and title_el.text
                 else name)
        groups.append((name, title))

    # One page per kernel group. ``:members:`` expands inner structs (e.g.
    # <kernel>_InitArgs) so their fields render, not just the struct name.
    #
    # Exception: a group whose header has an unclosed Doxygen group (``@{``
    # without a matching ``@}``) double-attributes a member, which trips a
    # duplicate-ID error under ``-W`` when ``:members:`` is used. Such groups
    # render without ``:members:`` until the header is fixed (code fix lands on
    # Bitbucket dev, tracked separately). Their struct fields will populate
    # automatically once the source group is balanced.
    discovered = {name for name, _title in groups}
    group_titles = {name: title for name, title in groups}

    for name, title in groups:
        underline = "=" * max(len(title), 3)
        with open(os.path.join(api_directory, f"{name}.rst"), "w",
                  encoding="utf-8") as fh:
            fh.write(f"{title}\n{underline}\n\n")
            opts = "" if name in _NO_MEMBERS_GROUPS else "\n   :members:"
            fh.write(f".. doxygengroup:: {name}{opts}\n")

    # Build a lookup for quick membership testing.
    grouped_stems = {stem for _cat, stems in _API_GROUP_ORDER for stem in stems}

    # Ungrouped pages (new kernels not yet in _API_GROUP_ORDER).
    ungrouped = sorted(discovered - grouped_stems)
    if ungrouped:
        print(f"WARNING: ungrouped API page(s): {', '.join(ungrouped)}")

    # -----------------------------------------------------------------------
    # Build landing pages for each _API_GROUP_ORDER caption.
    # landing_index_entries: ordered list of page slugs for api/index toctree.
    # -----------------------------------------------------------------------
    landing_index_entries = []  # page stems to list in api/index toctree
    all_emitted = set()  # track all RST pages for stale cleanup

    for category, stems in _API_GROUP_ORDER:
        # Collect group pages present in the XML.
        present = [s for s in stems if s in discovered]
        if not present:
            continue

        slug = _caption_to_slug(category)
        landing_file = os.path.join(api_directory, f"{slug}.rst")
        underline = "=" * max(len(category), 3)
        with open(landing_file, "w", encoding="utf-8") as fh:
            fh.write(f"{category}\n{underline}\n\n")
            fh.write(
                ".. toctree::\n"
                "   :maxdepth: 1\n\n"
            )
            for stem in present:
                fh.write(f"   {stem}\n")
            fh.write("\n")

        landing_index_entries.append(slug)
        all_emitted.add(slug)
        all_emitted.update(present)

    # -----------------------------------------------------------------------
    # Ungrouped: emit a single "other" landing if needed.
    # -----------------------------------------------------------------------
    if ungrouped:
        slug = "other"
        landing_file = os.path.join(api_directory, f"{slug}.rst")
        with open(landing_file, "w", encoding="utf-8") as fh:
            fh.write("Other\n=====\n\n")
            fh.write(".. toctree::\n   :maxdepth: 1\n\n")
            for stem in ungrouped:
                fh.write(f"   {stem}\n")
            fh.write("\n")
        landing_index_entries.append(slug)
        all_emitted.add(slug)
        all_emitted.update(ungrouped)

    all_emitted.add("index")

    # Remove stale .rst files from a previous build.
    for stale in glob.glob(os.path.join(api_directory, "*.rst")):
        stem = os.path.splitext(os.path.basename(stale))[0]
        if stem not in all_emitted:
            os.remove(stale)

    # -----------------------------------------------------------------------
    # api/index.rst: single toctree listing all landing pages in order.
    # -----------------------------------------------------------------------
    with open(os.path.join(api_directory, "index.rst"), "w",
              encoding="utf-8") as fh:
        fh.write(":icon: material/book-open-variant\n\n")
        fh.write("API Reference\n=============\n\n")
        fh.write("Per-kernel API documentation generated from the source "
                 "headers.\n\n")
        fh.write(
            ".. toctree::\n"
            "   :maxdepth: 2\n\n"
        )
        for entry in landing_index_entries:
            fh.write(f"   {entry}\n")
        fh.write("\n")


_generate_api_pages(xml_dir, _API_DIR)


# ---------------------------------------------------------------------------
# Performance pages (CSV-driven DataTables — one page per kernel)
# ---------------------------------------------------------------------------
# Each kernel has measured EVM cycle-count CSVs under perf_data/<device>/.
# We emit one RST page per kernel (with a subsection per device that has data)
# using ``.. raw:: html`` blocks containing <table class="perf-datatable"> so
# the browser-side perf-tables.js can initialise DataTables on them.

_PERF_DIR       = os.path.join(os.path.dirname(__file__), "perf")
_PERF_DATA_ROOT = os.path.join(os.path.dirname(__file__), "perf_data")

# (csv_subdir, human_title) — order preserved in each kernel page
_PERF_DEVICES = [
    ("c7504", "C7504 (AM62D)"),
    ("c7524", "C7524 (AM275/AM283)"),
]


def _csv_to_html_table(csv_path):
    """Return an HTML string for a <table class="perf-datatable"> from *csv_path*.

    Strips leading/trailing whitespace from every cell and HTML-escapes values.
    Returns an empty string if the file cannot be parsed.
    """
    import csv
    import html as html_mod
    try:
        with open(csv_path, newline="", encoding="utf-8") as fh:
            reader = csv.reader(fh)
            rows = list(reader)
    except OSError:
        return ""
    if not rows:
        return ""

    def esc(s):
        return html_mod.escape(s.strip())

    header = rows[0]
    data   = rows[1:]

    thead_cells = "".join(f"<th>{esc(c)}</th>" for c in header)
    tbody_rows  = "".join(
        "<tr>" + "".join(f"<td>{esc(c)}</td>" for c in row) + "</tr>"
        for row in data
        if any(c.strip() for c in row)  # skip blank rows
    )
    return (
        '<table class="perf-datatable">'
        f"<thead><tr>{thead_cells}</tr></thead>"
        f"<tbody>{tbody_rows}</tbody>"
        "</table>"
    )


def _kernel_briefs(xml_directory):
    """Map Doxygen group name -> brief description (one-liner) from the XML.

    Used to add a human-readable subtitle under each cryptic kernel name on
    the performance pages. Group name == CSV kernel stem, so the lookup is 1:1.
    """
    briefs = {}
    if not xml_directory or not os.path.isdir(xml_directory):
        return briefs
    for path in glob.glob(os.path.join(xml_directory, "group__*.xml")):
        try:
            comp = ET.parse(path).getroot().find("./compounddef[@kind='group']")
        except ET.ParseError:
            continue
        if comp is None:
            continue
        name_el = comp.find("compoundname")
        brief_el = comp.find("briefdescription")
        if name_el is None or not name_el.text:
            continue
        brief = " ".join("".join(brief_el.itertext()).split()) if brief_el is not None else ""
        if brief:
            briefs[name_el.text.strip()] = brief
    return briefs


def _generate_perf_pages_from_csv(perf_data_root, perf_dir, xml_directory=None):
    """Emit perf/index.rst + one perf/<kernel>.rst per kernel found in CSVs."""
    briefs = _kernel_briefs(xml_directory)
    # Collect the union of kernel stems across all device directories.
    kernel_stems = set()
    for slug, _title in _PERF_DEVICES:
        device_dir = os.path.join(perf_data_root, slug)
        if not os.path.isdir(device_dir):
            continue
        for fname in os.listdir(device_dir):
            if fname.endswith(".csv"):
                kernel_stems.add(fname[:-4])  # strip .csv

    if not kernel_stems:
        return

    os.makedirs(perf_dir, exist_ok=True)
    sorted_kernels = sorted(kernel_stems)

    # One RST page per kernel.
    for kernel in sorted_kernels:
        underline = "=" * max(len(kernel), 3)
        with open(os.path.join(perf_dir, f"{kernel}.rst"), "w",
                  encoding="utf-8") as fh:
            fh.write(f"{kernel}\n{underline}\n\n")
            desc = briefs.get(kernel)
            if desc:
                fh.write(f"*{desc}*\n\n")
            for slug, dev_title in _PERF_DEVICES:
                csv_path = os.path.join(perf_data_root, slug, f"{kernel}.csv")
                if not os.path.isfile(csv_path):
                    continue
                table_html = _csv_to_html_table(csv_path)
                if not table_html:
                    continue
                dev_under = "-" * max(len(dev_title), 3)
                fh.write(f"{dev_title}\n{dev_under}\n\n")
                fh.write(".. raw:: html\n\n")
                for line in table_html.splitlines():
                    fh.write(f"   {line}\n")
                fh.write("\n")

    # Landing index page.
    with open(os.path.join(perf_dir, "index.rst"), "w",
              encoding="utf-8") as fh:
        fh.write(":icon: material/chart-line\n\n")
        fh.write("Performance\n===========\n\n")
        fh.write(
            "Measured EVM warm-cycle counts per kernel. "
            "Tables are sortable and searchable; "
            "the header stays fixed while scrolling.\n\n"
        )
        fh.write(
            ".. toctree::\n"
            "   :maxdepth: 1\n"
            "   :caption: Performance\n\n"
        )
        for kernel in sorted_kernels:
            fh.write(f"   {kernel}\n")


_generate_perf_pages_from_csv(_PERF_DATA_ROOT, _PERF_DIR, xml_dir)

# ---------------------------------------------------------------------------
# MathJax (version 3 is the Sphinx default; AMS extensions load automatically)
# ---------------------------------------------------------------------------
# No custom macros needed for FFTLIB — rely on MathJax 3 defaults.

# ---------------------------------------------------------------------------
# Warning suppression
# ---------------------------------------------------------------------------
# Some Doxygen @code blocks in FFTLIB headers contain code that Pygments
# cannot highlight cleanly; suppress first-pass highlighting failures.
suppress_warnings = ["misc.highlighting_failure"]

pygments_style = "friendly"

# ---------------------------------------------------------------------------
# HTML output
# ---------------------------------------------------------------------------

html_theme        = "sphinx_immaterial"
html_title        = "FFTLIB Documentation"
html_static_path  = ["_static"]
html_logo         = "_static/img/ti_logo_mono.svg"

html_show_sphinx      = False
html_show_sourcelink  = False
html_copy_source      = False
html_last_updated_fmt = "%b %d, %Y"

html_theme_options = {
    # Palette: single light scheme — TI Red primary, teal accent.
    # No dark-mode toggle; user can tune later.
    "palette": [
        {
            "scheme":  "default",
            "primary": "red",
            "accent":  "teal",
        },
    ],
    # Features: clean navigation, no tabs (too much chrome).
    "features": [
        "navigation.top",   # back-to-top button
        "search.highlight", # highlight search terms after navigation
        "toc.follow",       # TOC sidebar tracks scroll position
    ],
    # Source repo shown in the header: GitHub logo + repo name.
    # The branch label ("main") is added via the source.html template
    # override (see _templates/partials/source.html).
    "repo_url":  "https://github.com/TexasInstruments/c7x_fftlib",
    "repo_name": "c7x_fftlib",
    "icon": {"repo": "material/github"},
}

# Template overrides (partials/source.html adds the branch badge).
templates_path = ["_templates"]

# ---------------------------------------------------------------------------
# Vendor JS/CSS for performance DataTables pages
# Load order matters: jQuery -> DataTables -> our init script.
# These are theme-independent (vendored assets) and work under sphinx-immaterial.
# ---------------------------------------------------------------------------

html_js_files = [
    "vendor/datatables/jquery.min.js",
    "vendor/datatables/datatables.min.js",
    "vendor/datatables/fixedHeader.min.js",
    "perf-tables.js",
]

html_css_files = [
    "vendor/datatables/datatables.min.css",
    "vendor/datatables/fixedHeader.min.css",
    # theme_overrides.css and immaterial_overrides.css are loaded via
    # setup(app).add_css_file() below so they are applied after base styles.
]

# ---------------------------------------------------------------------------
# Theme customisation hook
# ---------------------------------------------------------------------------

def setup(app):
    # Original RTD overrides (harmless, no matching .wy-* selectors in immaterial).
    app.add_css_file("css/theme_overrides.css")
    # Immaterial-specific overrides: WIP banner, TI teal header, sig colouring.
    app.add_css_file("css/immaterial_overrides.css")
