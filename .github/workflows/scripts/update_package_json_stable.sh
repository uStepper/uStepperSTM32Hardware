set -euo pipefail

URL="https://github.com/uStepper/uStepperSTM32Hardware/releases/download/v${BASE_VERSION}/${TARBALL}"

tmp="$(mktemp)"
jq --arg ver "$BASE_VERSION" \
   --arg url "$URL" \
   --arg file "$TARBALL" \
   --arg sha "SHA-256:${SHA256}" \
   --argjson size "$SIZE" '
  .packages[0].platforms as $plats
  | ($plats | map(select(.version | test("-dev\\.") | not))) as $stable
  | if ($stable|length) == 0 then
      error("No stable platform entries found to use as template (after removing -dev.*).")
    else
      .packages[0].platforms = [ {
        name: $stable[0].name,
        architecture: $stable[0].architecture,
        version: $ver,
        category: $stable[0].category,
        url: $url,
        archiveFileName: $file,
        checksum: $sha,
        size: $size,
        boards: $stable[0].boards,
        toolsDependencies: $stable[0].toolsDependencies
      } ]
    end
' package.json > "$tmp"
mv "$tmp" package.json

git config user.name "github-actions[bot]"
git config user.email "github-actions[bot]@users.noreply.github.com"
git add package.json
git commit -m "chore: update package.json for master [skip ci]"
git push origin HEAD:master