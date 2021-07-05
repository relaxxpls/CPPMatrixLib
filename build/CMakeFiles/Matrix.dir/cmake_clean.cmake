file(REMOVE_RECURSE
  "libMatrix.a"
  "libMatrix.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Matrix.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
