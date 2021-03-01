#/bin/sh

pod repo add IMQA-Specs https://github.com/onycom-imqa/IMQA-Cocoapods-Specs.git

# spec lint
pod spec lint --allow-warnings

CURRENT_DIR=$(pwd)

cd ~/.cocoapods/repo/IMQA-Specs

pod repo push --allow-warnings IMQA-Specs $CURRENT_DIR/IMQACrash.podspec