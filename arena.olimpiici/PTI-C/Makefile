# Configure CPP compilation flags
CXX_FLAGS=

CPP_FILES=$(wildcard *.cpp)
BIN_FILES=$(patsubst %.cpp, %.exe, ${CPP_FILES})

FILES_WITH_TEST=$(shell grep -l '// *TEST_ZIP: *https://arena.olimpiici.com/' *.cpp)
TEST_TARGETS=$(patsubst %.cpp, test.%, ${FILES_WITH_TEST})

all: $(BIN_FILES)

# Compile rules
# g++ -DEVAL -std=c++17 -O2 -pipe -static -s
%.exe: %.cpp
	@echo Compiling $<
	g++ $(CXX_FLAGS) $< -g -o $@


# Run tests rules
.test-data:
	mkdir -p .test-data

.test-data/run-helper: .test-data
	$(file >$@,$(value run_helper))
	chmod +x .test-data/run-helper

test-all: $(TEST_TARGETS)
	echo DONE

.test-data/%/test.zip: .test-data
	mkdir -p .test-data/$*
	curl -o .test-data/$*/test.zip -L $$(grep -oh 'https://arena.olimpiici.com/.*' $*.cpp)

.test-data/%/data: .test-data/%/test.zip
	mkdir -p $@
	cd $@ && unzip -uo ../test.zip

.test-data/%/result.txt: %.exe
	@.test-data/run-helper .test-data/$*

test-clean.%:
	rm -r .test-data/$*

test.%: .test-data/run-helper .test-data/%/test.zip .test-data/%/data .test-data/%/result.txt
	@echo '[$*]' Test results
	@cat .test-data/$*/result.txt
	@mv .test-data/$*/result.txt .test-data/$*/result.prev.txt
	@echo '[$*]' All Done!

test.%.exe: test.%
	@true

.PHONY: clean test-clean test.% .test-data/%/result.txt
.NOTINTERMEDIATE: .test-data/run-helper .test-data/%/test.zip .test-data/%/data

# Clean rules

test-clean:
	rm -rf .test-data

clean:
	rm -f *.exe

define run_helper
#!/bin/sh

THIS_DIR=$(cd `dirname $0`; pwd)
if [ -z "$1" ] ; then
	echo "Must specify test dir"
	exit 1
fi

TESTED_DIR=$(cd $1; pwd)
TESTED=$(basename $1)

RESULTS_DIR=${TESTED_DIR}/results/
SUMMARY=${TESTED_DIR}/result.txt
TESTS_DIR=${TESTED_DIR}/data/tests/
PROPS_FILE=${TESTED_DIR}/data/grade.properties

# READ limits
eval "$(grep '=' .test-data/${TESTED}/data/grade.properties | sed 's/^/MAX_/')"


echo "[${TESTED}]" Create results directory: ${RESULTS_DIR}
mkdir -p ${RESULTS_DIR}

TIME=$(which time)
TIME_FORMAT="TIME_SECONDS=%e;MAX_MEM_KB=%M;"
run_test() {
	IN=$1
	OUT_DIR=$2


	(
		echo "[${TESTED}]" Running `basename $IN`

		# Memory limit
		if [ "${MAX_MEM_KB}" ]; then
			ulimit -v ${MAX_MEM_KB}
		fi

		${TIME} -f "${TIME_FORMAT}" -o ${OUT_DIR}${BN}.time timeout -v  --preserve-status ${MAX_time} ./${TESTED}.exe < ${IN} > ${OUT_DIR}${BN}.out 2>${OUT_DIR}${BN}.err

	)

}

echo "[${TESTED}]" Running $(ls -1 ${TESTS_DIR}*.in | wc -l) tests with MAX_time=${MAX_time}s , MAX_memory=${MAX_memory}mb
MAX_MEM_KB=$(($MAX_memory * 1024))
rm ${RESULTS_DIR}/*
for f in ${TESTS_DIR}*.in; do
	BN=$(basename ${RESULTS_DIR}${f%.in})
	run_test ${f} ${RESULTS_DIR}
done

output_time(){
	VAL=$(grep = $1 2>/dev/null)
	if [ "$VAL" ]; then
		eval "$VAL"
		echo "${TIME_SECONDS}s / $((${MAX_MEM_KB}/1024 + 1))mb"
	else
		echo "- / -"
	fi
}

echo "[${TESTED}]" Create results summary file ${SUMMARY}
echo "***** Begin testrun `date -Is`"  > ${SUMMARY}
SUCCESS_COUNT=0
FAIL_COUNT=0
ERR_COUNT=0
for f in ${TESTS_DIR}*.sol; do
	BN=$(basename ${f%.sol})

	if [ -s ${RESULTS_DIR}${BN}.err ]; then
		echo "* $BN.in : FAIL (`output_time ${RESULTS_DIR}${BN}.time`)" >> ${SUMMARY}
		cat ${RESULTS_DIR}${BN}.err >> ${SUMMARY}
		ERR_COUNT=$(( ${ERR_COUNT} + 1 ))
	elif diff -W130 -y -ZBb $f ${RESULTS_DIR}${BN}.out > ${RESULTS_DIR}${BN}.diff; then
		echo "* $BN.in : PASS (`output_time ${RESULTS_DIR}${BN}.time`)" >> ${SUMMARY}
		rm ${RESULTS_DIR}${BN}.diff;
		rm ${RESULTS_DIR}${BN}.err;
		SUCCESS_COUNT=$(( ${SUCCESS_COUNT} + 1 ))
	else
		echo "* $BN.in : FAIL (`output_time ${RESULTS_DIR}${BN}.time`)" >> ${SUMMARY}
		printf '%.30s%65s\n' "$BN.sol" "$BN.out" "================" "===================" >> ${SUMMARY}
		cat ${RESULTS_DIR}${BN}.diff >> ${SUMMARY}
		FAIL_COUNT=$(( ${FAIL_COUNT} + 1 ))
	fi
done

echo "***** Summary:"  >> ${SUMMARY}
echo "Ran:         " $(ls -1 ${RESULTS_DIR}*.out | wc -l) >> ${SUMMARY}
echo "Passed:      " ${SUCCESS_COUNT} >> ${SUMMARY}
echo "Failed:      " ${FAIL_COUNT} >> ${SUMMARY}
echo "Errors:      " ${ERR_COUNT} >> ${SUMMARY}
echo "[${TESTED}]" Complete

endef
