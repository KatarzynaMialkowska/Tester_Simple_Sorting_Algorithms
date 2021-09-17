
.SUFFIXES: .cxx .o .x .hxx
NAME1 = bubble
NAME2 = counting
NAME3 = insertion
NAME4 = selection
NAME5 = radix
NAME6 = stdsort
NAME7 = tester
NAME8 = generator


CXX1 = $(NAME1).cxx
CXX2 = $(NAME2).cxx
CXX3 = $(NAME3).cxx
CXX4 = $(NAME4).cxx
CXX5 = $(NAME5).cxx
CXX6 = $(NAME6).cxx
CXX7 = $(NAME7).cxx
CXX8 = $(NAME8).cxx

EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
EXEC4 = $(NAME4).x
EXEC5 = $(NAME5).x
EXEC6 = $(NAME6).x
EXEC7 = $(NAME7).x
EXEC8 = $(NAME8).x


CO=g++
FLAGS= -std=c++11


.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5) $(EXEC6) $(EXEC7)  $(EXEC8)


$(EXEC1):
	$(CO) -o $@ $(CXX1) $(FLAGS) 

$(EXEC2): 
	$(CO) -o $@ $(CXX2) $(FLAGS)

$(EXEC3):
	$(CO) -o $@ $(CXX3) $(FLAGS) 

$(EXEC4):
	$(CO) -o $@ $(CXX4) $(FLAGS) 

$(EXEC5):
	$(CO) -o $@ $(CXX5) $(FLAGS) 

$(EXEC6):
	$(CO) -o $@ $(CXX6) $(FLAGS) 

$(EXEC7):
	$(CO) -o $@ $(CXX7) $(FLAGS) 

$(EXEC8):
	$(CO) -o $@ $(CXX8) $(FLAGS) 



##TESTER##

#tester is a program that compares all sortings in time,#
#and generates visualizations in the form of a chart in pdf.#
ctest: $(EXEC7)

.PHONY: test
test: ctest
	@echo "\n\t*START TEST*\n"
	@./$(EXEC7)


.PHONY: clean
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x *.pdf *.txt *.dat core core* a.out; rm -rf ${LIB_DIR}