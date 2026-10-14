import os
from conan import ConanFile
from conan.tools.files import copy

required_conan_version = ">=2.0.0"

class DbAdapterInterfaceConan(ConanFile):
    name = "db-adapter-interface"
    description = "Interface for library-agnostic API for C++ to work with a database"
    url = "https://github.com/systelab/cpp-db-adapter"
    homepage = "https://github.com/systelab/cpp-db-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "db", "sql", "adapter", "wrapper")
    license = "MIT"
    package_type = "header-library"
    exports_sources = "*.h", "*.inl"

    def package(self):
        copy(self, "*.h", src=self.source_folder, dst=os.path.join(self.package_folder, "include", "DbAdapterInterface"), excludes="DbAdapterTestUtilities/*.*")
        copy(self, "*.inl", src=self.source_folder, dst=os.path.join(self.package_folder, "include", "DbAdapterInterface"), excludes="DbAdapterTestUtilities/*.*")

    def package_id(self):
        self.info.clear()

    def package_info(self):
        self.cpp_info.bindirs = []
        self.cpp_info.libdirs = []
        self.cpp_info.set_property("cmake_file_name", "DbAdapterInterface")
        self.cpp_info.set_property("cmake_target_name", "DbAdapterInterface::DbAdapterInterface")
