//! @addtogroup Monintoring
//! @{
//
//****************************************************************************
//! @file stack_monitor.h
//! @brief This contains the prototypes, macros, constants or global variables
//!        for the Monitoring Application
//! @author Savindra Kumar(savindran1989@gmail.com)
//! @bug No known bugs.
//
//****************************************************************************
#ifndef STACK_MONITOR_H
#define STACK_MONITOR_H

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
//! @brief Init stack monitor
//! @param[in]    None
//! @param[out]   None
//! @return       None
//
void StackMonitorInit(void);

//
//! @brief Total stack size in bytes
//! @param[in]    None
//! @param[out]   None
//! @return       None
//
uint32_t TotalStackSize(void);

//
//! @brief Free stack size in bytes
//! @param[in]    None
//! @param[out]   None
//! @return       None
//
uint32_t FreeStackSize(void);

#endif // STACK_MONITOR_H
//*****************************************************************************
//                             End of file
//*****************************************************************************
//! @}
