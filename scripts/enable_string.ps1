# enable_string.ps1
# PowerShell script to generate string.impl.h based on the current environment

Copy-Item -Force "include/detail/String.impl.def" "include/detail/String.impl.h"
