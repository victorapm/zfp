#include "src/traitsf.h"
#include "src/block1.h"

#include "constants/1dFloat.h"

#define CFP_ARRAY_TYPE cfp_array1f
#define CFP_REF_TYPE cfp_ref1f
#define CFP_PTR_TYPE cfp_ptr1f
#define CFP_ITER_TYPE cfp_iter1f
#define SUB_NAMESPACE array1f
#define SCALAR float

#include "testCfpArray_source.c"
#include "testCfpArray1_source.c"

int main()
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(when_seededRandomSmoothDataGenerated_expect_ChecksumMatches),

    cmocka_unit_test(given_cfp_array1f_when_defaultCtor_expect_returnsNonNullPtr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_ctor_expect_paramsSet, setupCfpArrLargeComplete, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_copyCtor_expect_paramsCopied, setupCfpArrLargeComplete, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_copyCtor_expect_cacheCopied, setupCfpArrLargeComplete, teardownCfpArr),

    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_setRate_expect_rateSet, setupCfpArrMinimal, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_setCacheSize_expect_cacheSizeSet, setupCfpArrSmall, teardownCfpArr),

    cmocka_unit_test_setup_teardown(given_cfp_array1f_with_dirtyCache_when_flushCache_expect_cacheEntriesPersistedToMemory, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_clearCache_expect_cacheCleared, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_resize_expect_sizeChanged, setupCfpArrSmall, teardownCfpArr),

    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_setFlat_expect_entryWrittenToCacheOnly, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_getFlat_expect_entryReturned, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_set_expect_entryWrittenToCacheOnly, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_get_expect_entryReturned, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_get_ref_expect_arrayObjectValid, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_get_ptr_expect_arrayObjectValid, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_getFlatRef_expect_entryReturned, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_getFlatPtr_expect_entryReturned, setupCfpArrSmall, teardownCfpArr),

    cmocka_unit_test_setup_teardown(given_cfp_ref1f_when_get_expect_entryReturned, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ref1f_when_set_expect_arrayUpdated, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ref1f_when_copy_expect_arrayUpdated, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ref1f_when_get_ptr_expect_addressMatches, setupCfpArrSmall, teardownCfpArr),

    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_get_ref_expect_addressMatches, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_get_ref_at_expect_correct, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_lt_expect_less, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_gt_expect_more, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_leq_expect_less_or_eq, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_geq_expect_more_or_eq, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_eq_expect_same, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_neq_expect_different, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_distance_expect_correct, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_next_expect_correct, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_prev_expect_correct, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_inc_expect_correct, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_ptr1f_when_dec_expect_correct, setupCfpArrSmall, teardownCfpArr),

    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_get_ref_expect_correct, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_inc_expect_correct, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_dec_expect_correct, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_next_expect_correct, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_prev_expect_correct, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_distance_expect_correct, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_get_ref_at_expect_correct, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_lt_expect_less, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_gt_expect_more, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_leq_expect_less_or_eq, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_geq_expect_more_or_eq, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_eq_expect_same, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_neq_expect_different, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_iter1f_when_get_index_expect_correct, setupCfpArrSmall, teardownCfpArr),

    // fixed rate rounds up to multiples of 16 (omit fixed rate 8)
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_setArray_expect_compressedStreamChecksumMatches, setupFixedRate1, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_setArray_expect_compressedStreamChecksumMatches, setupFixedRate2, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_getArray_expect_decompressedArrChecksumMatches, setupFixedRate1, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_array1f_when_getArray_expect_decompressedArrChecksumMatches, setupFixedRate2, teardownCfpArr),
  };

  return cmocka_run_group_tests(tests, prepCommonSetupVars, teardownCommonSetupVars);
}
