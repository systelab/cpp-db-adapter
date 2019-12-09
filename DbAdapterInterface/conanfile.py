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
    settings = "os", "compiler", "build_type", "arch"
    options = {"boost": ["1.66.0", "1.67.0"]}
    default_options = {"boost":"1.67.0"}

    def configure(self):
        self.options["boost"].shared = True

    def requirements(self):
        self.requires(("boost/%s@conan/stable") % self.options.boost)

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy("*.so*", dst="bin", src="lib")

    def package(self):
        self.copy("*.h", dst="include/DbAdapterInterface")
        self.copy("*.inl", dst="include/DbAdapterInterface")

    def package_info(self):
        self.info.header_only()
