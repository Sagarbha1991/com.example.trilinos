IF(ROL_ENABLE_Intrepid2)
  TRIBITS_ADD_EXECUTABLE_AND_TEST(
    MiniTensorFUnctionInterface
    SOURCES test_01.cpp
    ARGS PrintItAll
    COMM serial mpi  
    PASS_REGULAR_EXPRESSION "PASSED"
    ADD_DIR_TO_NAME
    )
ENDIF()
