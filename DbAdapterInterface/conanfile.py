import os
from conans import ConanFile

class DbAdapterInterfaceConan(ConanFile):
    name = "DbAdapterInterface"
    description = "Interface for library-agnostic API for C++ to work with a database"
    url = "https://github.com/systelab/cpp-db-adapter"
    homepage = "https://github.com/systelab/cpp-db-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "db", "sql", "adapter", "wrapper")
    license = "MIT"
    generators = "cmake_find_package"
    exports_sources = "*.h", "*.inl"

    def package(self):
        self.copy("*.h", dst="include/DbAdapterInterface", excludes="DbAdapterTestUtilities/*.*")
        self.copy("*.inl", dst="include/DbAdapterInterface", excludes="DbAdapterTestUtilities/*.*")

    def package_info(self):
        self.info.header_only()
