# Makefile template file for FLAME
#
# FLAME is the FLAME source files
# SOURCE is the user source files
#
# The assumption is that the user only provides C files
# and a model files <file>.xml
#
DEFINES       = -DNONE
LIBMBOARD_DIR = libmboard
LIBMBOARD_INC = /home/pharting/lib/include/
LIBMBOARD_LIB = /home/pharting/lib/lib/

CC      = gcc
CFLAGS  = -std=c99 -Wall -I$(LIBMBOARD_INC) ${DEFINES}


CFLAGS += -O3

LDFLAGS = -L$(LIBMBOARD_LIB)
LIBS    = -lmboard_s  -lm -lgsl -lgslcblas

#FLAME source files
FLAME   = main.c memory.c xml.c messageboards.c partitioning.c rules.c timing.c

#FLAME auxilary files
AUX 	= stategraph.dot stategraph_colour.dot process_order_graph.dot Doxyfile latex.tex

# FLAME generated model files
SOURCES =  my_library_functions.c  Cons_Goods_UNIBI/Firm_Producer_Functions.c  Cons_Goods_UNIBI/Household_Consumer_Functions.c  Cons_Goods_UNIBI/Mall_functions.c  Cons_Goods_UNIBI/Mall_aux_functions.c  Credit_Ancona/Bank_Credit_Functions.c  Credit_Ancona/Firm_Credit_Functions.c  Credit_Ancona/Central_Bank_Functions.c  Credit_Ancona/IGFirm_dummy/IGFirm_Credit_Functions.c  Financial_Management_GREQAM/Firm_Financial_Management_Functions.c  Financial_Management_GREQAM/IGFirm_dummy/IGFirm_Financial_Management_Functions.c  Financial_Management_GREQAM/IGFirm_dummy/IGFirm_FM_aux_functions.c  Financial_UNIBI/ClearingHouse_Financial_Market_Functions.c  Financial_UNIBI/Household_Financial_Market_Functions.c  Financial_UNIBI/Firm_Financial_Market_Functions.c  Financial_UNIBI/IGFirm_Financial_Market_Functions.c  Financial_UNIBI/Central_Bank_Financial_Market_Functions.c  Financial_UNIBI/Government_Financial_Market_Functions.c  Financial_UNIBI/ClearingHouse_aux_functions.c  Financial_UNIBI/Household_aux_functions.c  Inv_Goods_Vintage/IGFirm_Producer_Functions.c  Labour_UNIBI/Firm_Employer_Functions.c  Labour_UNIBI/Household_Employee_Functions.c  Labour_UNIBI/Labour_aux_functions.c  Government_GREQAM/Government_Functions.c  Statistical_Office_UNIBI/Firm_Statistics_Functions.c  Statistical_Office_UNIBI/Household_Statistics_Functions.c  Statistical_Office_UNIBI/Eurostat_Functions.c  Statistical_Office_UNIBI/Eurostat_aux_functions.c  Statistical_Office_UNIBI/Bank_Statistics_Functions.c  Statistical_Office_UNIBI/Mall_Statistics_Functions.c  Statistical_Office_UNIBI/IGFirm_dummy/IGFirm_Statistics_Functions.c  Market_Research/Household_Market_Research_Functions.c  Market_Research/Firm_market_research_functions.c 
HEADERS = header.h low_primes.h mboard.h  Firm_agent_header.h  Household_agent_header.h  Mall_agent_header.h  IGFirm_agent_header.h  Eurostat_agent_header.h  Bank_agent_header.h  Government_agent_header.h  CentralBank_agent_header.h  ClearingHouse_agent_header.h 

DEPS    = Makefile header.h low_primes.h

OBJECTS = $(SOURCES:.c=.o) $(FLAME:.c=.o)
EXECUTABLE = main
RM = rm -f

all: $(SOURCES) $(FLAME) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

$(OBJECTS): $(DEPS)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE) $(EXECUTABLE).exe
vclean:
	$(RM) main $(EXECUTABLE) $(EXECUTABLE).exe $(OBJECTS)  $(FLAME) $(HEADERS)  $(AUX) Makefile
