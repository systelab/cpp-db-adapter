from conans import ConanFile, tools


class DbAdapterConan(ConanFile):
    name = "DbAdapter"
    description = "Library-agnostic API for C++ to work with a database"
    url = "https://github.com/systelab/cpp-db-adapter"
    homepage = "https://github.com/systelab/cpp-db-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "db", "sql", "adapter", "wrapper")
    license = "MIT"
    generators = "cmake_find_package"
    settings = "os", "compiler", "build_type", "arch"
    default_options = "boost:shared=True"

    def requirements(self):
        self.requires("TestUtilitiesInterface/1.0.1@systelab/stable")
        self.requires("boost/1.67.0@conan/stable")

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy("*.so*", dst="bin", src="lib")

    def package(self):
        self.copy("*.h", dst="include/DbAdapterInterface", src="DbAdapterInterface")
        self.copy("*.inl", dst="include/DbAdapterInterface", src="DbAdapterInterface")
        self.copy("*.h", dst="include/DbAdapterTestUtilities", src="DbAdapterTestUtilities")
        self.copy("*DbAdapterTestUtilities.lib", dst="lib", keep_path=False)
        self.copy("*DbAdapterTestUtilities.pdb", dst="lib", keep_path=False)
        self.copy("*DbAdapterTestUtilities.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
