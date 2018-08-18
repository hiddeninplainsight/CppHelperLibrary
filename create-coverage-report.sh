#!/usr/bin/env bash

echo ===== Cleaning previous coverage data =====
make -C cmake-build-debug/ clean
find . -name *.gcno | xargs rm
find . -name *.gcda | xargs rm
rm -rf coverage

mkdir coverage

set -e

# make the projects
echo ===== Building =====
make -C cmake-build-debug

# create baseline coverage data file
lcov --config-file lcovrc --capture -i --directory . --output-file coverage/coverage_base.info

set +e

# perform tests
echo ===== Running Tests =====
cmake-build-debug/tests/tests

set -e

# create test coverage data file
lcov --config-file lcovrc --capture --directory . --output-file coverage/coverage_tests.info

# combine baseline and test coverage data
lcov --config-file lcovrc -a coverage/coverage_base.info -a coverage/coverage_tests.info -o coverage/coverage.info

lcov --config-file lcovrc --remove coverage/coverage.info third-party-libraries/\*\*/\* /usr/\*\*/\* -o coverage/coverage_filtered.info

# create the coverage report
genhtml --config-file lcovrc --branch-coverage coverage/coverage_filtered.info --output-directory coverage
