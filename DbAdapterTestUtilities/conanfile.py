import os
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain
from conan.tools.files import collect_libs, copy

required_conan_version = ">=2.0.0"

class DbAdapterTestUtilitiesConan(ConanFile):
    name = "db-adapter-test-utilities"
    description = "Test utilities for library-agnostic API for C++ to work with a database"
    url = "https://github.com/systelab/cpp-db-adapter"
    homepage = "https://github.com/systelab/cpp-db-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "db", "sql", "adapter", "wrapper")
    license = "MIT"
    settings = "os", "compiler", "build_type", "arch"

    # The sources include their own headers as "DbAdapterTestUtilities/...", so in the Conan cache they must live in a folder with that name
    def export_sources(self):
        dst = os.path.join(self.export_sources_folder, "DbAdapterTestUtilities")
        for pattern in ("*.cpp", "*.h", "CMakeLists.txt"):
            copy(self, pattern, src=self.recipe_folder, dst=dst, excludes="build*/*")

    @property
    def _sources_folder(self):
        if os.path.exists(os.path.join(self.source_folder, "CMakeLists.txt")):
            return self.source_folder
        return os.path.join(self.source_folder, "DbAdapterTestUtilities")

    def requirements(self):
        self.requires("gtest/1.14.0")
        if self.version is None:
            self.requires(f"db-adapter-interface/{os.environ['VERSION']}")
        else:
            self.requires(f"db-adapter-interface/{self.version}")

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

        dep_dst = os.path.join(self.build_folder, "bin")
        for dep in self.dependencies.values():
            for bindir in dep.cpp_info.bindirs:
                copy(self, "*.dll", dst=dep_dst, src=bindir)
            for libdir in dep.cpp_info.libdirs:
                copy(self, "*.dylib*", dst=dep_dst, src=libdir)
                copy(self, "*.so*", dst=dep_dst, src=libdir)

    def build(self):
        cmake = CMake(self)
        cmake.configure(build_script_folder=self._sources_folder)
        cmake.build()

    def package(self):
        copy(self, "*.h", src=self._sources_folder, dst=os.path.join(self.package_folder, "include", "DbAdapterTestUtilities"), keep_path=True)
        copy(self, "*DbAdapterTestUtilities.lib", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "*DbAdapterTestUtilities.pdb", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "*DbAdapterTestUtilities.a", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)

    def package_info(self):
        self.cpp_info.libs = collect_libs(self)
