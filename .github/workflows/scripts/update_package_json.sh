set -euo pipefail

URL="https://github.com/uStepper/uStepperSTM32Hardware/releases/download/${DEV_VERSION}/${TARBALL}"

tmp="$(mktemp)"
jq --arg ver "$DEV_VERSION" \
   --arg url "$URL" \
   --arg file "$TARBALL" \
   --arg sha "SHA-256:${SHA256}" \
   --arg size "$SIZE" '
  .packages[0].platforms |=
    ([{
      name: .[0].name,
      architecture: .[0].architecture,
      version: $ver,
      category: .[0].category,
      url: $url,
      archiveFileName: $file,
      checksum: $sha,
      size: $size,
      boards: .[0].boards,
      toolsDependencies: .[0].toolsDependencies
    }] + .)
' package.json > "$tmp"
mv "$tmp" package_test.json

git config user.name "github-actions[bot]"
git config user.email "github-actions[bot]@users.noreply.github.com"
git add package_test.json
git commit -m "chore: update package.json for develop [skip ci]"
git push origin HEAD:feature-CI/CD