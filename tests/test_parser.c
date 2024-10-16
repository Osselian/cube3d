#include "../project/incs/cub3D.h"
#include "../unity/src/unity.h"
#include <dirent.h>

//не удалять
void setUp(void)
{
}

//не удалять
void tearDown(void)
{
}

void test_meta_init_bad(void)
{
    char            *bad_maps_path = "../project/maps/bad/";
    char            *argv[2];
    t_meta          metadata;
    struct dirent   *de;

    DIR *dr = opendir(bad_maps_path);
    if (!dr)
        TEST_IGNORE_MESSAGE("Invalid maps path");

    while ((de = readdir(dr)) != NULL)
    {
       argv[1] = de->d_name;
       TEST_ASSERT_EQUAL(1, meta_init(argv, &metadata));
    }
    closedir(dr);

}

void test_meta_init_good(void)
{
    char            *good_maps_path = "../project/maps/good/";
    char            *argv[2];
    t_meta          metadata;
    struct dirent   *de;

    DIR *dr = opendir(good_maps_path);
    if (!dr)
        TEST_IGNORE_MESSAGE("Invalid maps path");

    while ((de = readdir(dr)) != NULL)
    {
       argv[1] = de->d_name;
       TEST_ASSERT_EQUAL(0, meta_init(argv, &metadata));
    }
}