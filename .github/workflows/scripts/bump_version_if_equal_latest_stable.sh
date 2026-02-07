set -euo pipefail

BASE_VERSION="$(cat VERSION | tr -d ' \n\r\t')"

git fetch --tags --force

# Find seneste stable tag (ingen -dev.*)
LAST_STABLE="$(git tag -l --sort=-v:refname \
  | grep -E '^[0-9]+\.[0-9]+\.[0-9]+$' \
  | head -n1)"

echo "BASE_VERSION=$BASE_VERSION"
echo "LAST_STABLE=$LAST_STABLE"

if [[ -n "$LAST_STABLE" && "$BASE_VERSION" == "$LAST_STABLE" ]]; then
  IFS='.' read -r major minor patch <<<"$BASE_VERSION"
  patch=$((patch + 1))
  NEW_BASE="${major}.${minor}.${patch}"
  echo "$NEW_BASE" > VERSION
  BASE_VERSION="$NEW_BASE"

  git config user.name "github-actions[bot]"
  git config user.email "github-actions[bot]@users.noreply.github.com"
  git add VERSION
  git commit -m "ci: bump VERSION to $BASE_VERSION [skip ci]"
  git push origin HEAD:develop
fi

DEV_VERSION="${BASE_VERSION}-dev.${GITHUB_RUN_NUMBER}"
echo "DEV_VERSION=$DEV_VERSION" >> "$GITHUB_ENV"
