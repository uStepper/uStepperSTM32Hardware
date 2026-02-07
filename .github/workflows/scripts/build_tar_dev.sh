#!/usr/bin/env bash
set -euo pipefail

ROOT="uStepperSTM32Hardware-${DEV_VERSION}"
OUT="${ROOT}.tar.bz2"

stage="$(mktemp -d)"
mkdir -p "${stage}/${ROOT}"

# Kopiér alt ind i den ene rod-mappe
cp -R cores libraries system variants tools \
  boards.txt keywords.txt platform.txt programmers.txt \
  "${stage}/${ROOT}/"

# Lav tarball med ÉN root dir
tar -cjf "${OUT}" -C "${stage}" "${ROOT}"

sha256="$(sha256sum "$OUT" | awk '{print $1}')"
size="$(stat -c%s "$OUT")"

echo "TARBALL=$OUT" >> "$GITHUB_ENV"
echo "SHA256=$sha256" >> "$GITHUB_ENV"
echo "SIZE=$size" >> "$GITHUB_ENV"

rm -rf "${stage}"