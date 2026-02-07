set -euo pipefail

OUT="uStepperSTM32Hardware-${DEV_VERSION}.tar.bz2"

tar -cjf "$OUT" \
  cores libraries system variants tools \
  boards.txt keywords.txt platform.txt programmers.txt

sha256="$(sha256sum "$OUT" | awk '{print $1}')"
size="$(stat -c%s "$OUT")"

echo "TARBALL=$OUT" >> "$GITHUB_ENV"
echo "SHA256=$sha256" >> "$GITHUB_ENV"
echo "SIZE=$size" >> "$GITHUB_ENV"