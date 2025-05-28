#include "../libs/unity/unity.h"
#include "../libs/unity/unity.c"
#include "../src/cp.c"

char srcFilePath[] = "../samples/src.txt";
char dstFilePath[] = "../samples/dest.txt";

void setUp(void)
{
    char buffer[] = "hello world";
    FILE *file = fopen(srcFilePath, "wb");
    if (file == NULL)
    {
        TEST_FAIL_MESSAGE("Failed to create sample file for testing.");
    }
    fwrite(buffer, sizeof(char), sizeof(buffer) - 1, file);
    fclose(file);
}

void tearDown(void)
{
    remove(srcFilePath);
}

void test_cp(void)
{
    TEST_ASSERT_EQUAL_INT(0, cp(srcFilePath, dstFilePath));

    FILE *srcFile = fopen(srcFilePath, "rb");
    FILE *dstFile = fopen(dstFilePath, "rb");

    TEST_ASSERT_NOT_NULL(srcFile);
    TEST_ASSERT_NOT_NULL(dstFile);
    TEST_ASSERT_EQUAL_INT(sizeof(srcFile), sizeof(dstFile));
}

int main(void)
{
    UNITY_BEGIN();

    // Run the tests
    RUN_TEST(test_cp);

    return UNITY_END();
}