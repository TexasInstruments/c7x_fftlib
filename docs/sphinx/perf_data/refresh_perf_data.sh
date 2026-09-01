#!/usr/bin/env bash
# Refresh vendored FFTLIB performance CSVs from the nightly pipeline.
# The docs build reads these committed snapshots (see conf.py
# _generate_perf_pages_from_csv); re-run this when new nightly numbers land,
# then commit the updated CSVs. Intended for manual use or a Jenkins step.
#
# Usage: docs/sphinx/perf_data/refresh_perf_data.sh [BUILD_TAG]
#   BUILD_TAG defaults to the pinned build below; override to pull a newer run.
set -euo pipefail

BUILD_TAG="${1:-xlib_vlop_spt_pipeline-FFTLIB-1449}"
BASE="http://epswnas.itg.ti.com/xlib_audio/fftlib/nightly/${BUILD_TAG}/logs"
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

for dev in C7504 C7524; do
  slug="$(echo "$dev" | tr '[:upper:]' '[:lower:]')"
  dst="${HERE}/${slug}"
  mkdir -p "$dst"
  tmp="$(mktemp -d)"
  echo "Fetching ${dev} csv.tar ..."
  curl -fsSL -o "${tmp}/csv.tar" "${BASE}/${dev}/target/csv.tar"
  tar xf "${tmp}/csv.tar" -C "$dst"
  echo "  -> $(ls "${dst}"/*.csv | wc -l) CSVs in ${dst}"
done
echo "Done. Review 'git diff docs/sphinx/perf_data' and commit."
