//! @addtogroup UARTApp
//! @{
//
//****************************************************************************
//! @file uart_app.h
//! @brief This contains the prototypes, macros, constants or global variables
//!        for the UART Application
//! @author Savindra Kumar(savindran1989@gmail.com)
//! @bug No known bugs.
//
//****************************************************************************
#ifndef UART_APP_H
#define UART_APP_H

//****************************************************************************
//                           Includes
//****************************************************************************

//****************************************************************************
//                           Constants and typedefs
//****************************************************************************

//****************************************************************************
//                           Global variables
//****************************************************************************

//****************************************************************************
//                           Global Functions
//****************************************************************************
//
//! @brief Handle UART app
//! @param[in]    None
//! @param[out]   None
//! @return       None
//
void UARTInit(void);

void UARTPrint(char *buf); 
int GetUARTData(uint8_t *buf);

#endif // SGP_APP_H
//****************************************************************************
//                             End of file
//****************************************************************************
//! @}
