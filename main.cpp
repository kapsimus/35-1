#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>
#include <filesystem>

int main() {
    //задание 1
    auto array = {1, 2, 3, 4, 5, 5, 4, 3, 10, 11, 12};
    for (auto i: array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //задание 2
    std::vector<int> array2 = {1, 2, 3, 4, 5, 5, 4, 3, 10, 11, 12};
    auto foo = [](std::vector<int> arr){
        std::unordered_set<int> keys;
        std::unique_ptr<std::vector<int>> out = std::make_unique<std::vector<int>>();
        for (auto key: arr) {
            keys.insert(key);
        }
        for (auto key: keys) {
            out->push_back(key);
        }
        return out;
    };
    std::unique_ptr<std::vector<int>> keys = foo(array2);
    for (auto key: *keys) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    //задание 3
    std::string path = "f:\\PROGS", ext = ".txt";
    std::cout << "Enter path: ";
    std::cin >> path;
    std::cout << "Enter extension: ";
    std::cin >> ext;
    auto recursiveGetFileNamesByExtension =
            [](std::filesystem::path path, const std::string extension) {
        std::shared_ptr<std::vector<std::string>> out = std::make_shared<std::vector<std::string>>();
        for(auto& p: std::filesystem::recursive_directory_iterator(path)) {
            if(is_regular_file(p.path())) {
                if (!p.path().extension().compare(extension)) {
                    out->push_back(p.path().filename().string());
                }
            }
        }
        return out;
    };
    std::shared_ptr<std::vector<std::string>> files = recursiveGetFileNamesByExtension(path, ext);
    if (!files->empty()) {
        for (auto file: *files) {
            std::cout << file << std::endl;
        }
    }
    return 0;
}
