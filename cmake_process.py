
import os

home_path = os.path.expanduser("~")
vcpkg_path = os.path.join(home_path, "vcpkg")

vcpkg_cmake_path = os.path.join(home_path, 
        "vcpkg/scripts/buildsystems/vcpkg.cmake")

src_dir = os.path.dirname(__file__)

build_dir = os.path.join(src_dir, "build")

command = f"cmake -B {build_dir} -S {src_dir} -DCMAKE_TOOLCHAIN_FILE={vcpkg_cmake_path}"

print(command)
os.system(command)

