#/bin/sh

PRESET_VERSION=$(cat VERSION)

git add .
git commit -m "<release>: Release $PRESET_VERSION"

git tag v$PRESET_VERSION
git push origin v$PRESET_VERSION
git push origin master