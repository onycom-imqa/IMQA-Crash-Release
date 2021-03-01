#/bin/sh

## 현재 버전 정보 가져오기 
PRESET_VERSION=$(cat VERSION)

## 현재 버전으로 릴리즈하기 
git add .
git commit -m "<release>: Release $PRESET_VERSION"

git tag v$PRESET_VERSION
git push origin v$PRESET_VERSION
git push origin main