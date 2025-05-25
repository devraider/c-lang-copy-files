#bin/bash


LIBS="libs"
UNITY_DIR="${LIBS}/unity"

mkdir -p ${UNITY_DIR}

# Download Unity files
echo "Downloading Unity framework ⌛️"
curl -s -o "$UNITY_DIR/unity.c" https://raw.githubusercontent.com/ThrowTheSwitch/Unity/master/src/unity.c
curl -s -o "$UNITY_DIR/unity.h" https://raw.githubusercontent.com/ThrowTheSwitch/Unity/master/src/unity.h

echo "✅Reolved dependencies🚀"