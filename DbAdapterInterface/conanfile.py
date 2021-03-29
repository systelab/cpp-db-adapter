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
    options = {"boost": ["1.66.0", "1.67.0", "1.72.0"]}
    default_options = {"boost": "1.72.0"}
    exports_sources = "*"

    def configure(self):
        self.options["boost"].shared = True

    def requirements(self):
        if self.options.boost == "1.66.0":
            self.requires("boost/1.66.0@conan/stable")
        elif self.options.boost == "1.67.0":
            self.requires("boost/1.67.0@conan/stable")
        elif self.options.boost == "1.72.0":
            self.requires("boost/1.72.0#50e13743ed3c867fe95f151e113bc1ba")
        else:
            self.requires(("boost/%s") % self.options.boost)

    def package(self):
        self.copy("*.h", dst="include/DbAdapterInterface")
        self.copy("*.inl", dst="include/DbAdapterInterface")

    def package_info(self):
        self.info.header_only()
