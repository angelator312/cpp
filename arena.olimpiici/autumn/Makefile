# Configure CPP compilation flags
CXX_FLAGS=

CPP_FILES=$(wildcard *.cpp)
BIN_FILES=$(patsubst %.cpp, %.exe, ${CPP_FILES})

FILES_WITH_TEST=$(shell grep -l '// *TEST_ZIP: *https://arena.olimpiici.com/' *.cpp)
TEST_TARGETS=$(patsubst %.cpp, test.%, ${FILES_WITH_TEST})

all: $(BIN_FILES)

# Compile rules
%.exe: %.cpp
	@echo Compiling $<
	g++ $(CXX_FLAGS) $< -g -o $@


# Run tests rules
.test-data:
	mkdir -p .test-data

test-all: $(TEST_TARGETS)
	echo DONE

.test-data/%/test.zip: .test-data
	mkdir -p .test-data/$*
	curl -o .test-data/$*/test.zip -L $$(grep -oh 'https://arena.olimpiici.com/.*' $*.cpp)

.test-data/%/data: .test-data/%/test.zip
	mkdir -p $@
	cd $@ && unzip ../test.zip

.test-data/%/result.txt: %.exe
	@echo '[$*]' Create results directory: .test-data/$*/results/
	@mkdir -p .test-data/$*/results/
	@echo '[$*]' Running $$(ls -1 .test-data/$*/data/tests/*.in | wc -l) tests
	@for f in .test-data/$*/data/tests/*.in; do \
		BN=$$(basename .test-data/$*/results/$${f%.in});\
		./$*.exe < $$f > .test-data/$*/results/$${BN}.out; \
	done;
	@echo '[$*]' Create results summary file $@
	@echo "***** Begin testrun `date -Is`"  > $@
	@for f in .test-data/$*/data/tests/*.sol; do \
		BN=$$(basename .test-data/$*/results/$${f%.sol});\
		if diff -W130 -y $$f .test-data/$*/results/$${BN}.out > .test-data/$*/results/$${BN}.diff; then\
			echo "* $$BN.in : PASS" >> $@;\
			rm .test-data/$*/results/$${BN}.diff;\
		else\
			echo "* $$BN.in : FAIL" >> $@;\
			printf '%.30s%65s\n' "$$BN.sol" "$$BN.out" "================" "===================" >> $@;\
			cat .test-data/$*/results/$${BN}.diff >> $@;\
		fi;\
	done;
	@echo "***** Summary:"  >> $@
	@echo "Ran:         " $$(ls -1 .test-data/$*/results/*.out | wc -l) >> $@
	@echo "Failed:      " $$(ls -1 .test-data/$*/results/*.diff | wc -l) >> $@
	@echo '[$*]' Complete


test.%: .test-data/%/test.zip .test-data/%/data .test-data/%/result.txt
	@echo '[$*]' Test results
	@cat .test-data/$*/result.txt
	@mv .test-data/$*/result.txt .test-data/$*/result.prev.txt
	@echo '[$*]' All Done!

test.%.exe: test.%
	@true

.PHONY: clean test-clean test.% .test-data/%/result.txt
.NOTINTERMEDIATE: .test-data/%/test.zip .test-data/%/data

# Clean rules

test-clean:
	rm -rf .test-data

clean:
	rm -f *.exe

