import os
from conans import ConanFile, CMake, tools

class DbAdapterTestUtilitiesConan(ConanFile):
    name = "DbAdapterTestUtilities"
    description = "Test utilities for library-agnostic API for C++ to work with a database"
    url = "https://github.com/systelab/cpp-db-adapter"
    homepage = "https://github.com/systelab/cpp-db-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "db", "sql", "adapter", "wrapper")
    license = "MIT"
    generators = "cmake_find_package"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "*.cpp", "*.h", "CMakeLists.txt", "!build*"

    def requirements(self):
        self.requires("gtest/1.14.0@")
        if ("%s" % self.version) == "None":
            self.requires(f"DbAdapterInterface/{os.environ['VERSION']}@systelab/{os.environ['CHANNEL']}")
        else:
            self.requires(f"DbAdapterInterface/{self.version}@systelab/{self.channel}")

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder=".")
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy("*.so*", dst="bin", src="lib")

    def package(self):
        self.copy("*.h", dst="include/DbAdapterTestUtilities", keep_path=True)
        self.copy("*DbAdapterTestUtilities.lib", dst="lib", keep_path=False)
        self.copy("*DbAdapterTestUtilities.pdb", dst="lib", keep_path=False)
        self.copy("*DbAdapterTestUtilities.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
