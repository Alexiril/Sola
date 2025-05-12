# This file is just a little script to make PNG images from Graphvis dependency
$ErrorActionPreference = "Stop"
cd "build"

$directory = "dependency-graph"
$destination = "dependency-graph-image"

if (-Not (Test-Path -Path $destination)) {
    New-Item -Path $destination -ItemType Directory | Out-Null
}

Get-ChildItem -Path $directory | ForEach-Object {
    if ($_.Extension -ne ".png") {
        Write-Host "Processing $($_.Name)"
        $outputFile = Join-Path -Path $destination -ChildPath "$($_.Name).png"
        & dot -Tpng -o $outputFile "$($_.FullName)"
    }
}

cd ..