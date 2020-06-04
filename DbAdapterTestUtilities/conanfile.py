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
    options = {"boost": ["1.66.0", "1.67.0", "1.71.0"], "gtest": ["1.7.0", "1.8.1", "1.10.0"]}
    default_options = {"boost":"1.71.0", "gtest": "1.10.0"}
    exports_sources = "*"

    def configure(self):
        self.options["DbAdapterInterface"].boost = self.options.boost

    def requirements(self):
        if self.options.gtest == "1.7.0":
            self.requires("gtest/1.7.0@systelab/stable")
        elif self.options.gtest == "1.8.1":
            self.requires("gtest/1.8.1")
        else:
            self.requires("gtest/1.10.0")

        self.requires("TestUtilitiesInterface/1.0.4@systelab/stable")
        if ("%s" % self.version) == "None":
            self.requires("DbAdapterInterface/%s@systelab/stable" % os.environ['VERSION'])
        else:
            self.requires("DbAdapterInterface/%s@systelab/stable" % self.version)

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
