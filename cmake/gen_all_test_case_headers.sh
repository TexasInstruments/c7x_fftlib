#!/bin/bash


pushd () {
    command pushd "$@" > /dev/null
}

popd () {
    command popd "$@" > /dev/null
}

export THIS_SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null && pwd)"

export REPO_WORK_DIR=${THIS_SCRIPT_DIR}/../
# declare -a kernels_target=($(find ${REPO_WORK_DIR}/src/*/* -maxdepth 0 -type d ! \( -iname "common" \) | grep -o -P '.{0}src/.*' | cut -c 5-))

declare -a kernels_target=($(find ${REPO_WORK_DIR}/src/fft_c7x/* \
   -maxdepth 0 -type d | grep -o "src/.*" | cut -c 5-))

kernels_target+=($(find ${REPO_WORK_DIR}/src/fft_c7xmma/* \
   -maxdepth 0 -type d | grep -o "src/.*" | cut -c 5-))

echo "${kernels_target[@]}"


# for i in "${kernels_target[@]}"; do
gen_test_case(){
    full_path=${1} # get full path like "fft_c7x/FFTLIB_fft1d_i16sc_c16sc_o16sc"
    kernel_name=$(basename ${full_path}) # extract just kernel name

    mkdir -p ${THIS_SCRIPT_DIR}/../test/${full_path}/test_data
    if [ -d "${THIS_SCRIPT_DIR}/../test/fft_c7x/FFTLIB_idat_gen/${kernel_name}" ]; then

	echo ""
	echo "##############################################################"
	echo ""
	echo " Generating test case headers for ${kernel_name}"

	echo "##############################################################"
	echo ""

	pushd ${THIS_SCRIPT_DIR}/../test/fft_c7x/FFTLIB_idat_gen/${kernel_name}
	DEVICE=${DEVICE} python3 gen_data.py -a
	popd
	echo ""
    fi
}
# done

export -f gen_test_case

parallel --gnu -j0  gen_test_case ::: ${kernels_target[@]}


