:icon: material/file-tree

Repository Layout
=================

Top-level structure of the FFTLIB repository:

.. raw:: html

   <style>
   .repo-tree summary::-webkit-details-marker { display: none; }
   .repo-tree summary::before {
     content: "\25B6";
     font-size: 0.65em;
     color: #007C8C;
     flex-shrink: 0;
     transition: transform 0.15s;
     margin-right: 0.3em;
   }
   .repo-tree details[open] > summary::before { transform: rotate(90deg); }
   .rt-root {
     padding: 0.4rem 0.8rem;
     background: #115566;
     color: #ffffff;
     font-weight: 700;
     font-size: 0.88rem;
     letter-spacing: 0.03em;
     border-radius: 3px;
     margin-bottom: 0.3em;
   }
   .rt-l1 { padding-left: 1.2rem; }
   .rt-l2 { padding-left: 2.4rem; }
   details.rt-folder > summary {
     font-weight: 600;
     color: #0D3040;
     cursor: pointer;
     display: flex;
     align-items: baseline;
     gap: 0.3em;
     padding: 0.15em 0;
   }
   details.rt-folder > summary .rt-name { color: #007C8C; }
   details.rt-folder > summary .rt-desc {
     color: #547880;
     font-weight: 400;
     font-size: 0.8rem;
   }
   .rt-file {
     display: flex;
     align-items: baseline;
     gap: 0.4em;
     padding: 0.15em 0.5em;
     border-radius: 3px;
   }
   .rt-file:hover { background: #EAF4F6; }
   .rt-file .rt-icon { color: #547880; font-size: 0.85em; }
   .rt-file .rt-name { color: #0D3040; }
   .rt-file .rt-desc { color: #547880; font-size: 0.79rem; margin-left: 0.2em; }
   details.rt-folder[open] > .rt-children {
     border-left: 1px solid #E0E0E0;
     margin-left: 1.4rem;
     padding-left: 0.5rem;
   }
   </style>

   <div class="repo-tree">
   <div class="rt-root">fftlib/</div>

   <!-- top-level leaf files -->
   <div class="rt-file rt-l1"><span class="rt-icon">&#128196;</span><span class="rt-name">CMakeLists.txt</span><span class="rt-desc">Top-level CMake entry point</span></div>
   <div class="rt-file rt-l1"><span class="rt-icon">&#128196;</span><span class="rt-name">CMakePresets.json</span><span class="rt-desc">Shared, tracked build presets</span></div>
   <div class="rt-file rt-l1"><span class="rt-icon">&#128196;</span><span class="rt-name">README.md</span><span class="rt-desc">Overview, features, kernel list</span></div>
   <div class="rt-file rt-l1"><span class="rt-icon">&#128196;</span><span class="rt-name">LICENSE</span><span class="rt-desc">Apache-2.0 license text</span></div>
   <div class="rt-file rt-l1"><span class="rt-icon">&#128196;</span><span class="rt-name">CONTRIBUTING.md</span><span class="rt-desc">Contribution policy</span></div>
   <div class="rt-file rt-l1"><span class="rt-icon">&#128196;</span><span class="rt-name">makefile.am62dx.c75x.ti-c7000</span><span class="rt-desc">Standalone makefile (AM62D / C7504)</span></div>
   <div class="rt-file rt-l1"><span class="rt-icon">&#128196;</span><span class="rt-name">makefile.am275x.c75x.ti-c7000</span><span class="rt-desc">Standalone makefile (AM275 / C7524)</span></div>

   <!-- cmake/ — leaf folder, no children shown -->
   <div class="rt-file rt-l1"><span class="rt-icon">&#128193;</span><span class="rt-name">cmake/</span><span class="rt-desc">CMake helper modules (toolchains, docs, tests)</span></div>

   <!-- src/ -->
   <details class="rt-folder rt-l1" open>
     <summary><span class="rt-name">src/</span> <span class="rt-desc">Kernel implementations &#8212; one folder per kernel group</span></summary>
     <div class="rt-children">
       <div class="rt-file rt-l2"><span class="rt-icon">&#128193;</span><span class="rt-name">common/</span><span class="rt-desc">Shared types, buffer params, inlines, platform defs</span></div>
       <div class="rt-file rt-l2"><span class="rt-icon">&#128193;</span><span class="rt-name">fft_c7x/</span><span class="rt-desc">C7&#8482; SE/SA FFT kernels (1-D FFT/IFFT, batched variants)</span></div>
       <div class="rt-file rt-l2"><span class="rt-icon">&#128193;</span><span class="rt-name">fft_c7xmma/</span><span class="rt-desc">C7&#8482;+MMA DFT kernels (C7100/C7120 only)</span></div>
       <div class="rt-file rt-l2"><span class="rt-icon">&#128193;</span><span class="rt-name">linalg_c7xmma/</span><span class="rt-desc">C7&#8482;+MMA linear algebra kernels</span></div>
     </div>
   </details>

   <!-- test/ -->
   <details class="rt-folder rt-l1" open>
     <summary><span class="rt-name">test/</span> <span class="rt-desc">Test drivers and generated vectors</span></summary>
     <div class="rt-children">
       <div class="rt-file rt-l2"><span class="rt-icon">&#128193;</span><span class="rt-name">common/</span><span class="rt-desc">Shared test infrastructure</span></div>
       <details class="rt-folder rt-l2" open>
         <summary><span class="rt-name">fft_c7x/</span> <span class="rt-desc">Per-kernel test drivers and idat generators</span></summary>
         <div class="rt-children">
           <div class="rt-file rt-l2"><span class="rt-icon">&#128193;</span><span class="rt-name">FFTLIB_idat_gen/</span><span class="rt-desc">Python test-vector generators</span></div>
           <div class="rt-file rt-l2"><span class="rt-icon">&#128193;</span><span class="rt-name">FFTLIB_&lt;kernel&gt;/</span><span class="rt-desc">Per-kernel test driver + data</span></div>
         </div>
       </details>
     </div>
   </details>

   <!-- docs/ -->
   <details class="rt-folder rt-l1" open>
     <summary><span class="rt-name">docs/</span> <span class="rt-desc">Documentation</span></summary>
     <div class="rt-children">
       <div class="rt-file rt-l2"><span class="rt-icon">&#128193;</span><span class="rt-name">doxygen/</span><span class="rt-desc">Doxyfiles, content pages, performance HTML</span></div>
       <div class="rt-file rt-l2"><span class="rt-icon">&#128193;</span><span class="rt-name">sphinx/</span><span class="rt-desc">Sphinx site (conf.py, rst, TI theme)</span></div>
     </div>
   </details>

   </div>

Kernel sources — ``src/fft_c7x/FFTLIB_<kernel>/``
--------------------------------------------------

Each C7™ SE/SA kernel lives in its own folder under ``src/fft_c7x/``. The public
header carries the Doxygen documentation that this site renders.

.. list-table::
   :header-rows: 1
   :widths: 45 55

   * - File
     - Contents
   * - ``FFTLIB_<kernel>.h``
     - Public API — init/exec prototypes and Doxygen documentation
   * - ``FFTLIB_<kernel>_cn.cpp``
     - C-native reference implementation (``_cn`` / ``NATC``)
   * - ``FFTLIB_<kernel>_ci.cpp``
     - C7™ intrinsic-optimized implementation (``_ci`` / ``OPT``)
   * - ``FFTLIB_<kernel>_priv.h``, ``*_common.*``
     - Internal helpers — not part of the public API
   * - ``CMakeLists.txt``
     - Build rules for the kernel

``src/common/`` holds cross-kernel definitions: ``FFTLIB_types.h`` (status
codes, kernel handle, function-style enums), ``FFTLIB_bufParams.h``,
``FFTLIB_inlines.h``, ``FFTLIB_utility.h``, ``TI_platforms.h``, and per-device
subdirectories (``c71/``, ``c7100/``, ``c7120/``, ``c7504/``).

MMA DFT kernels — ``src/fft_c7xmma/``
--------------------------------------

The C7™+MMA DFT kernels (``FFTLIB_FFT_*``) target C7100 and C7120 cores only
and are **not** supported on AM62D (C7504) or AM275 (C7524).

Tests — ``test/fft_c7x/FFTLIB_<kernel>/``
------------------------------------------

.. list-table::
   :header-rows: 1
   :widths: 45 55

   * - File
     - Contents
   * - ``FFTLIB_<kernel>_d.c``
     - Test driver (entry point) for the kernel
   * - ``FFTLIB_<kernel>_check.{cpp,h}``
     - Result verification against the reference
   * - ``FFTLIB_<kernel>_idat.{c,h}``
     - Generated test vectors (see :doc:`getting_started`)

Test-vector generators — ``test/fft_c7x/FFTLIB_idat_gen/<kernel>/``
--------------------------------------------------------------------

.. list-table::
   :header-rows: 1
   :widths: 45 55

   * - File
     - Contents
   * - ``gen_data.py``
     - Generates the ``_idat`` vectors for the kernel
   * - ``test_cases_list.csv``
     - Parametric test-case definitions (sizes, types, options)

Other folders
-------------

- ``cmake/`` — build-system modules: toolchain files (``c7x.cmake``, ``gcc.cmake``),
  documentation (``doxygen.cmake``), and test/vector generation
  (``test.cmake``, ``gen_test_cases.cmake``).
- ``docs/doxygen/`` — Doxygen configuration, narrative content pages, and the
  prebuilt performance HTML tables.
- ``docs/sphinx/`` — this documentation site (``conf.py``, ``.rst`` sources, and
  the TI-branded theme assets under ``_static/``).
