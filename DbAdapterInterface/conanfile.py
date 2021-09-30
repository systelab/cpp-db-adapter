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
    options = {"boost": ["1.66.0", "1.67.0", "1.72.0", "1.75.0", "1.76.0"]}
    default_options = {"boost": "1.76.0"}
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
        elif self.options.boost == "1.75.0":
            self.requires("boost/1.75.0#32c81e4e89c54b95b2c2c198fe3cb65f")
        elif self.options.boost == "1.76.0":
            self.requires("boost/1.76.0#329123a826d0a53fef8318ec3e729a52")
        else:
            self.requires(("boost/%s") % self.options.boost)

    def package(self):
        self.copy("*.h", dst="include/DbAdapterInterface")
        self.copy("*.inl", dst="include/DbAdapterInterface")

    def package_info(self):
        self.info.header_only()
