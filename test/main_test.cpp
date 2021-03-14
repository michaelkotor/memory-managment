//
// Created by Michael Kotor on 2021-03-14.
//

#include <item.h>
#include <storage.h>
#include "gtest/gtest.h"

TEST(storage, create_pointer_storage)
{
    storage *storage = new class storage;
    EXPECT_TRUE(storage != nullptr);
}

TEST(stoarege, create_object_storage)
{
    storage storage;
    EXPECT_NO_THROW(storage);
}

TEST(storage_check_content, check_volume_1)
{
    process process{"Name", 2};
    storage storage;
    EXPECT_EQ(0, storage.allocate(process));
    EXPECT_EQ(process.name, storage.getProcess("Name").name);
    EXPECT_EQ(process.size, storage.getProcess("Name").size);
}

TEST(storage_check_content, check_volume_2)
{
    process process{"Name", 3};
    storage storage;
    EXPECT_EQ(2, storage.allocate(process));
    EXPECT_EQ(process.name, storage.getProcess("Name").name);
    EXPECT_EQ(process.size, storage.getProcess("Name").size);
}

TEST(storage_check_content, check_volume_3)
{
    process process{"Name", 5};
    storage storage;
    EXPECT_EQ(4, storage.allocate(process));
    EXPECT_EQ(process.name, storage.getProcess("Name").name);
    EXPECT_EQ(process.size, storage.getProcess("Name").size);
}

TEST(storage_check_content, check_volume_4)
{
    process process{"Name", 17};
    storage storage;
    EXPECT_EQ(6, storage.allocate(process));
    EXPECT_EQ(process.name, storage.getProcess("Name").name);
    EXPECT_EQ(process.size, storage.getProcess("Name").size);
}

TEST(storage_check_content, check_volume_5)
{
    process process{"Name", 17};
    storage storage;
    EXPECT_EQ(6, storage.allocate(process));
    EXPECT_EQ(process.name, storage.getProcess("Name").name);
    EXPECT_EQ(process.size, storage.getProcess("Name").size);
}

TEST(storage_check_content, check_volume_6)
{
    process process{"Name", 33};
    storage storage;
    EXPECT_EQ(8, storage.allocate(process));
    EXPECT_EQ(process.name, storage.getProcess("Name").name);
    EXPECT_EQ(process.size, storage.getProcess("Name").size);
}

TEST(storage_check_content, check_volume_7)
{
    process process{"Name", 65};
    storage storage;
    EXPECT_EQ(9, storage.allocate(process));
    EXPECT_EQ(process.name, storage.getProcess("Name").name);
    EXPECT_EQ(process.size, storage.getProcess("Name").size);
}

TEST(storage_check_content, check_volume_8)
{
    process process{"Name", 128};
    storage storage;
    EXPECT_EQ(9, storage.allocate(process));
    EXPECT_EQ(process.name, storage.getProcess("Name").name);
    EXPECT_EQ(process.size, storage.getProcess("Name").size);
}

TEST(storage_check_content, check_free)
{
    process process{"Name", 128};
    storage storage;
    storage.allocate(process);
    storage.free(process);
    try {
        storage.getProcess("Name");
        FAIL() << "Expected std::invalid_argument";
    } catch (std::invalid_argument const & err) {
        EXPECT_EQ(err.what(), std::string("No such process"));
    }
}

TEST(storage_check_content, check_not_existing)
{
    storage storage;
    try {
        storage.getProcess("Not existing");
        FAIL() << "Expected std::invalid_argument";
    } catch (std::invalid_argument const & err) {
        EXPECT_EQ(err.what(), std::string("No such process"));
    }
}

TEST(storage_check_content, check_multiple_1)
{
    process process_1{"Name1", 2};
    process process_2{"Name2", 2};
    storage storage;
    EXPECT_EQ(0, storage.allocate(process_1));
    EXPECT_EQ(1, storage.allocate(process_2));
    EXPECT_EQ(process_1.name, storage.getProcess("Name1").name);
    EXPECT_EQ(process_1.size, storage.getProcess("Name1").size);
    EXPECT_EQ(process_2.name, storage.getProcess("Name2").name);
    EXPECT_EQ(process_2.size, storage.getProcess("Name2").size);
}

TEST(storage_check_content, check_multiple_2)
{
    process process_1{"Name1", 4};
    process process_2{"Name2", 2};
    storage storage;
    EXPECT_EQ(2, storage.allocate(process_1));
    EXPECT_EQ(0, storage.allocate(process_2));
    EXPECT_EQ(process_1.name, storage.getProcess("Name1").name);
    EXPECT_EQ(process_1.size, storage.getProcess("Name1").size);
    EXPECT_EQ(process_2.name, storage.getProcess("Name2").name);
    EXPECT_EQ(process_2.size, storage.getProcess("Name2").size);
}

TEST(storage_check_content, check_multiple_3)
{
    process process_1{"Name1", 64};
    process process_2{"Name2", 2};
    process process_3{"Name3", 33};
    storage storage;
    EXPECT_EQ(8, storage.allocate(process_1));
    EXPECT_EQ(0, storage.allocate(process_2));
    EXPECT_EQ(9, storage.allocate(process_3));
    EXPECT_EQ(process_1.name, storage.getProcess("Name1").name);
    EXPECT_EQ(process_1.size, storage.getProcess("Name1").size);
    EXPECT_EQ(process_2.name, storage.getProcess("Name2").name);
    EXPECT_EQ(process_2.size, storage.getProcess("Name2").size);
    EXPECT_EQ(process_3.name, storage.getProcess("Name3").name);
    EXPECT_EQ(process_3.size, storage.getProcess("Name3").size);
}





