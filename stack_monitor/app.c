//! @addtogroup Application
//! @brief Application for cli testing
//! @{
//
//****************************************************************************
//! @file app.c
//! @brief Implement application functions
//! @author Savindra Kumar(savindran1989@gmail.com)
//! @bug No known bugs.
//
//****************************************************************************
//****************************************************************************
//                           Includes
//****************************************************************************
//standard header files
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//user defined header files
#include "app.h"
#include "stack_monitor.h"

//****************************************************************************
//                           Defines and typedefs
//****************************************************************************
#define PROJECT_TITLE     "Cli for Nucleo F411RE"
#define FIRMWARE_VERSION  "0.0.1"

//****************************************************************************
//                           external variables
//****************************************************************************

//****************************************************************************
//                           Private variables
//****************************************************************************

//****************************************************************************
//                           Private Functions
//****************************************************************************

//****************************************************************************
//                    G L O B A L  F U N C T I O N S
//****************************************************************************
uint8_t app_ShowInfo(const char **ppcParams,
                     uint8_t ucParamCount,
                     char *pcResult)
{
    uint16_t usLengthInBytes = 0;

    usLengthInBytes += sprintf(pcResult + usLengthInBytes, "\r\n");
    usLengthInBytes += sprintf(pcResult + usLengthInBytes,
                               "\tPROJECT.. [ %s ]\r\n",
                               PROJECT_TITLE);
    usLengthInBytes += sprintf(pcResult + usLengthInBytes,
                               "\tVERSION.. [ %s ]\r\n",
                               FIRMWARE_VERSION);
    usLengthInBytes += sprintf(pcResult + usLengthInBytes,
                               "\tDATE..... [ %s %s]\r\n",
                               __DATE__, __TIME__);

    return true;
}//end AppShowInfo


uint8_t app_GetFreeStack(const char **ppcParams,
                         uint8_t ucParamCount,
                         char *pcResult)
{
    uint16_t usLengthInBytes = 0;
    uint32_t total_stack_size = TotalStackSize();
    uint32_t free_stack_size  = FreeStackSize();

    usLengthInBytes += sprintf(pcResult, 
                               "\r\nTotal stack size = %u bytes\r\n",
                               total_stack_size);
 
    usLengthInBytes += sprintf(pcResult + usLengthInBytes, 
                               "Free stack size = %u bytes\r\n",
                               free_stack_size);    
    
    return true;
}//end app_GetFreeStack

//****************************************************************************
//                           L O C A L  F U N C T I O N S
//****************************************************************************

//****************************************************************************
//                             End of file
//****************************************************************************
//! @}
