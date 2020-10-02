//! @addtogroup Monitoring
//! @brief Monitor system
//! @{
//!
//*****************************************************************************
//! @file stack_monitor.c
//! @brief stack monitoring
//! @author Savindra Kumar(savindran1989@gmail.com)
//! @bug No known bugs.
//!
//*****************************************************************************
//*****************************************************************************
//                           Includes
//*****************************************************************************
//standard header files
#include <stdint.h>
#include <stddef.h>
//user defined header files
#include "stack_monitor.h"

//*****************************************************************************
//                           Defines and typedefs
//*****************************************************************************
#define MAGIC_NUM   0xAAAAAAAA

//*****************************************************************************
//                           Private Functions
//*****************************************************************************


//*****************************************************************************
//                           external variables
//*****************************************************************************
//Symbols which are resolved at linking time 
extern uint32_t* CSTACK$$Limit;
extern uint32_t* CSTACK$$Base;

//*****************************************************************************
//                           Private variables
//*****************************************************************************
static uint32_t* stack_bottom_adress = NULL;
static uint32_t* stack_top_address = NULL;

//*****************************************************************************
//                    G L O B A L  F U N C T I O N S
//*****************************************************************************
void StackMonitorInit(void)
{
    uint32_t* stack_current_address = (uint32_t*)__get_SP();
    
    stack_bottom_adress = (uint32_t*)&CSTACK$$Base;
    stack_top_address   = (uint32_t*)&CSTACK$$Limit;
    
    stack_current_address =  stack_current_address - 4;
   
    uint32_t* tmp = stack_bottom_adress; 
    
    while (stack_current_address > tmp)
    {
        *stack_current_address = MAGIC_NUM;
        stack_current_address = stack_current_address - 4;
    }
    
    *stack_bottom_adress = MAGIC_NUM;    
}//end StackMonitorInit

uint32_t TotalStackSize(void)
{
    uint32_t stack_size = (uint32_t)stack_top_address - (uint32_t)stack_bottom_adress;
    
    return stack_size;
}//end TotalStackSize

uint32_t FreeStackSize(void)
{
    uint32_t* tmp = stack_bottom_adress;
    
    tmp = tmp + 4;
    
    while (MAGIC_NUM == *tmp)
    {
        tmp = tmp + 4;
    }
    
    uint32_t free_stack_size = (uint32_t)tmp - (uint32_t)stack_bottom_adress;
    
    return free_stack_size;  
}//end FreeStackSize

//*****************************************************************************
//                           L O C A L  F U N C T I O N S
//*****************************************************************************


//*****************************************************************************
//                             End of file
// ****************************************************************************
//! @}
