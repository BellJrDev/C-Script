#!/bin/bash
# BASH script to  to generate string.impl.h based on the current environment

cp include/detail/String.impl.def include/detail/String.impl.h
echo "[bash] ✅ string.impl.h generated successfully"
