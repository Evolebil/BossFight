#!/bin/bash
set -e
BIN_DIR="bin"
EXE="$BIN_DIR/BossFight.exe"
MINGW_BIN="/usr/x86_64-w64-mingw32/bin"
PREFIX="x86_64-w64-mingw32-objdump"

copied=""

copy_recursive() {
    local dll="$1"
    [[ " $copied " == *" $dll "* ]] && return 0
    local src="$MINGW_BIN/$dll"
    [[ -f "$src" ]] || return 0
    cp -v "$src" "$BIN_DIR/"
    copied="$copied $dll"
    local deps
    deps=$($PREFIX -p "$src" | grep "DLL Name" | awk '{print $3}')
    for d in $deps; do
        copy_recursive "$d"
    done
}

needed=$($PREFIX -p "$EXE" | grep "DLL Name" | awk '{print $3}')
for dll in $needed; do
    copy_recursive "$dll"
done

echo "Готово — проверь $BIN_DIR, там должен лежать .exe + все .dll"
