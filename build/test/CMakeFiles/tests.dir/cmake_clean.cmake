file(REMOVE_RECURSE
  "tests.pdb"
  "tests"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/tests.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
