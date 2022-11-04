echo "Hi I am Atif"
git clone https://github.com/pybind/pybind11.git ../forked_repo/pybind11
chmod +x run_project.sh
./run_project.sh
rm -rf build
echo "Showing All"
tree
