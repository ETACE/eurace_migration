/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"



union pu_bank_account_update 
{
    m_bank_account_update *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_account_update_message(int id, int bank_id, double payment_account)
 * \brief Add bank_account_update message by calling internal and processing.
 * \param id Message variable.
 * \param bank_id Message variable.
 * \param payment_account Message variable.
 */
void add_bank_account_update_message(int id, int bank_id, double payment_account)
{
    int rc;
	m_bank_account_update msg;
    
    msg.id = id;
    msg.bank_id = bank_id;
    msg.payment_account = payment_account;
    
    
    rc = MB_AddMessage(b_bank_account_update, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_account_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_account_update' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_account_update' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_account_update* getInternalMessage_bank_account_update(void)
{
    static m_bank_account_update *msg_prev = NULL;
    union pu_bank_account_update msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_account_update); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_account_update' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_account_update' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_account_update, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_account_update' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_account_update' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_account_update * get_first_bank_account_update_message()
 * \brief Get the first bank_account_update message in the bank_account_update message list.
 * \return The first message in the list.
 */
m_bank_account_update * get_first_bank_account_update_message()
{
	return getInternalMessage_bank_account_update();
}

/** \fn xmachine_message_bank_account_update * get_next_bank_account_update_message(xmachine_message_bank_account_update * current)
 * \brief Get the next bank_account_update message in the bank_account_update message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_account_update * get_next_bank_account_update_message(m_bank_account_update * current)
{
	return getInternalMessage_bank_account_update();
}


union pu_bank_to_central_bank_account_update 
{
    m_bank_to_central_bank_account_update *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_to_central_bank_account_update_message(int id, double payment_account, double ecb_debt)
 * \brief Add bank_to_central_bank_account_update message by calling internal and processing.
 * \param id Message variable.
 * \param payment_account Message variable.
 * \param ecb_debt Message variable.
 */
void add_bank_to_central_bank_account_update_message(int id, double payment_account, double ecb_debt)
{
    int rc;
	m_bank_to_central_bank_account_update msg;
    
    msg.id = id;
    msg.payment_account = payment_account;
    msg.ecb_debt = ecb_debt;
    
    
    rc = MB_AddMessage(b_bank_to_central_bank_account_update, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_to_central_bank_account_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_to_central_bank_account_update' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_to_central_bank_account_update' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_to_central_bank_account_update* getInternalMessage_bank_to_central_bank_account_update(void)
{
    static m_bank_to_central_bank_account_update *msg_prev = NULL;
    union pu_bank_to_central_bank_account_update msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_to_central_bank_account_update); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_to_central_bank_account_update' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_to_central_bank_account_update' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_to_central_bank_account_update, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_to_central_bank_account_update' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_to_central_bank_account_update' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_to_central_bank_account_update * get_first_bank_to_central_bank_account_update_message()
 * \brief Get the first bank_to_central_bank_account_update message in the bank_to_central_bank_account_update message list.
 * \return The first message in the list.
 */
m_bank_to_central_bank_account_update * get_first_bank_to_central_bank_account_update_message()
{
	return getInternalMessage_bank_to_central_bank_account_update();
}

/** \fn xmachine_message_bank_to_central_bank_account_update * get_next_bank_to_central_bank_account_update_message(xmachine_message_bank_to_central_bank_account_update * current)
 * \brief Get the next bank_to_central_bank_account_update message in the bank_to_central_bank_account_update message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_to_central_bank_account_update * get_next_bank_to_central_bank_account_update_message(m_bank_to_central_bank_account_update * current)
{
	return getInternalMessage_bank_to_central_bank_account_update();
}


union pu_gov_to_central_bank_account_update 
{
    m_gov_to_central_bank_account_update *ptr;
    void *ptr_anon;
};

/** \fn void add_gov_to_central_bank_account_update_message(int id, double payment_account, double gdp)
 * \brief Add gov_to_central_bank_account_update message by calling internal and processing.
 * \param id Message variable.
 * \param payment_account Message variable.
 * \param gdp Message variable.
 */
void add_gov_to_central_bank_account_update_message(int id, double payment_account, double gdp)
{
    int rc;
	m_gov_to_central_bank_account_update msg;
    
    msg.id = id;
    msg.payment_account = payment_account;
    msg.gdp = gdp;
    
    
    rc = MB_AddMessage(b_gov_to_central_bank_account_update, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'gov_to_central_bank_account_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_to_central_bank_account_update' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_to_central_bank_account_update' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_gov_to_central_bank_account_update* getInternalMessage_gov_to_central_bank_account_update(void)
{
    static m_gov_to_central_bank_account_update *msg_prev = NULL;
    union pu_gov_to_central_bank_account_update msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_gov_to_central_bank_account_update); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'gov_to_central_bank_account_update' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'gov_to_central_bank_account_update' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_gov_to_central_bank_account_update, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'gov_to_central_bank_account_update' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_to_central_bank_account_update' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_gov_to_central_bank_account_update * get_first_gov_to_central_bank_account_update_message()
 * \brief Get the first gov_to_central_bank_account_update message in the gov_to_central_bank_account_update message list.
 * \return The first message in the list.
 */
m_gov_to_central_bank_account_update * get_first_gov_to_central_bank_account_update_message()
{
	return getInternalMessage_gov_to_central_bank_account_update();
}

/** \fn xmachine_message_gov_to_central_bank_account_update * get_next_gov_to_central_bank_account_update_message(xmachine_message_gov_to_central_bank_account_update * current)
 * \brief Get the next gov_to_central_bank_account_update message in the gov_to_central_bank_account_update message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_gov_to_central_bank_account_update * get_next_gov_to_central_bank_account_update_message(m_gov_to_central_bank_account_update * current)
{
	return getInternalMessage_gov_to_central_bank_account_update();
}


union pu_wage_payment 
{
    m_wage_payment *ptr;
    void *ptr_anon;
};

/** \fn void add_wage_payment_message(int firm_id, int worker_id, double payment, double productivity, double average_specific_skills, int employer_igfirm, double specific_skill)
 * \brief Add wage_payment message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 * \param payment Message variable.
 * \param productivity Message variable.
 * \param average_specific_skills Message variable.
 * \param employer_igfirm Message variable.
 * \param specific_skill Message variable.
 */
void add_wage_payment_message(int firm_id, int worker_id, double payment, double productivity, double average_specific_skills, int employer_igfirm, double specific_skill)
{
    int rc;
	m_wage_payment msg;
    
    msg.firm_id = firm_id;
    msg.worker_id = worker_id;
    msg.payment = payment;
    msg.productivity = productivity;
    msg.average_specific_skills = average_specific_skills;
    msg.employer_igfirm = employer_igfirm;
    msg.specific_skill = specific_skill;
    
    
    rc = MB_AddMessage(b_wage_payment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'wage_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'wage_payment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'wage_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_wage_payment* getInternalMessage_wage_payment(void)
{
    static m_wage_payment *msg_prev = NULL;
    union pu_wage_payment msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_wage_payment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'wage_payment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'wage_payment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_wage_payment, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'wage_payment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'wage_payment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_wage_payment * get_first_wage_payment_message()
 * \brief Get the first wage_payment message in the wage_payment message list.
 * \return The first message in the list.
 */
m_wage_payment * get_first_wage_payment_message()
{
	return getInternalMessage_wage_payment();
}

/** \fn xmachine_message_wage_payment * get_next_wage_payment_message(xmachine_message_wage_payment * current)
 * \brief Get the next wage_payment message in the wage_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_wage_payment * get_next_wage_payment_message(m_wage_payment * current)
{
	return getInternalMessage_wage_payment();
}


union pu_quality_price_info_1 
{
    m_quality_price_info_1 *ptr;
    void *ptr_anon;
};

/** \fn void add_quality_price_info_1_message(int mall_id, int mall_region_id, int firm_id, int firm_region_id, double quality, double price, int available)
 * \brief Add quality_price_info_1 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param mall_region_id Message variable.
 * \param firm_id Message variable.
 * \param firm_region_id Message variable.
 * \param quality Message variable.
 * \param price Message variable.
 * \param available Message variable.
 */
void add_quality_price_info_1_message(int mall_id, int mall_region_id, int firm_id, int firm_region_id, double quality, double price, int available)
{
    int rc;
	m_quality_price_info_1 msg;
    
    msg.mall_id = mall_id;
    msg.mall_region_id = mall_region_id;
    msg.firm_id = firm_id;
    msg.firm_region_id = firm_region_id;
    msg.quality = quality;
    msg.price = price;
    msg.available = available;
    
    
    rc = MB_AddMessage(b_quality_price_info_1, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'quality_price_info_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_1' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quality_price_info_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_quality_price_info_1* getInternalMessage_quality_price_info_1(void)
{
    static m_quality_price_info_1 *msg_prev = NULL;
    union pu_quality_price_info_1 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_quality_price_info_1); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'quality_price_info_1' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'quality_price_info_1' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_quality_price_info_1, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'quality_price_info_1' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_1' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_quality_price_info_1 * get_first_quality_price_info_1_message()
 * \brief Get the first quality_price_info_1 message in the quality_price_info_1 message list.
 * \return The first message in the list.
 */
m_quality_price_info_1 * get_first_quality_price_info_1_message()
{
	return getInternalMessage_quality_price_info_1();
}

/** \fn xmachine_message_quality_price_info_1 * get_next_quality_price_info_1_message(xmachine_message_quality_price_info_1 * current)
 * \brief Get the next quality_price_info_1 message in the quality_price_info_1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_quality_price_info_1 * get_next_quality_price_info_1_message(m_quality_price_info_1 * current)
{
	return getInternalMessage_quality_price_info_1();
}


union pu_quality_price_info_2 
{
    m_quality_price_info_2 *ptr;
    void *ptr_anon;
};

/** \fn void add_quality_price_info_2_message(int mall_id, int mall_region_id, int firm_id, int firm_region_id, double quality, double price, int available)
 * \brief Add quality_price_info_2 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param mall_region_id Message variable.
 * \param firm_id Message variable.
 * \param firm_region_id Message variable.
 * \param quality Message variable.
 * \param price Message variable.
 * \param available Message variable.
 */
void add_quality_price_info_2_message(int mall_id, int mall_region_id, int firm_id, int firm_region_id, double quality, double price, int available)
{
    int rc;
	m_quality_price_info_2 msg;
    
    msg.mall_id = mall_id;
    msg.mall_region_id = mall_region_id;
    msg.firm_id = firm_id;
    msg.firm_region_id = firm_region_id;
    msg.quality = quality;
    msg.price = price;
    msg.available = available;
    
    
    rc = MB_AddMessage(b_quality_price_info_2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'quality_price_info_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quality_price_info_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_quality_price_info_2* getInternalMessage_quality_price_info_2(void)
{
    static m_quality_price_info_2 *msg_prev = NULL;
    union pu_quality_price_info_2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_quality_price_info_2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'quality_price_info_2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'quality_price_info_2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_quality_price_info_2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'quality_price_info_2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_quality_price_info_2 * get_first_quality_price_info_2_message()
 * \brief Get the first quality_price_info_2 message in the quality_price_info_2 message list.
 * \return The first message in the list.
 */
m_quality_price_info_2 * get_first_quality_price_info_2_message()
{
	return getInternalMessage_quality_price_info_2();
}

/** \fn xmachine_message_quality_price_info_2 * get_next_quality_price_info_2_message(xmachine_message_quality_price_info_2 * current)
 * \brief Get the next quality_price_info_2 message in the quality_price_info_2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_quality_price_info_2 * get_next_quality_price_info_2_message(m_quality_price_info_2 * current)
{
	return getInternalMessage_quality_price_info_2();
}


union pu_update_mall_stock 
{
    m_update_mall_stock *ptr;
    void *ptr_anon;
};

/** \fn void add_update_mall_stock_message(int mall_id, int firm_id, int firm_region_id, double quantity, double quality, double price, double previous_price)
 * \brief Add update_mall_stock message by calling internal and processing.
 * \param mall_id Message variable.
 * \param firm_id Message variable.
 * \param firm_region_id Message variable.
 * \param quantity Message variable.
 * \param quality Message variable.
 * \param price Message variable.
 * \param previous_price Message variable.
 */
void add_update_mall_stock_message(int mall_id, int firm_id, int firm_region_id, double quantity, double quality, double price, double previous_price)
{
    int rc;
	m_update_mall_stock msg;
    
    msg.mall_id = mall_id;
    msg.firm_id = firm_id;
    msg.firm_region_id = firm_region_id;
    msg.quantity = quantity;
    msg.quality = quality;
    msg.price = price;
    msg.previous_price = previous_price;
    
    
    rc = MB_AddMessage(b_update_mall_stock, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'update_mall_stock' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'update_mall_stock' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'update_mall_stock' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_update_mall_stock* getInternalMessage_update_mall_stock(void)
{
    static m_update_mall_stock *msg_prev = NULL;
    union pu_update_mall_stock msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_update_mall_stock); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'update_mall_stock' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'update_mall_stock' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_update_mall_stock, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'update_mall_stock' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'update_mall_stock' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_update_mall_stock * get_first_update_mall_stock_message()
 * \brief Get the first update_mall_stock message in the update_mall_stock message list.
 * \return The first message in the list.
 */
m_update_mall_stock * get_first_update_mall_stock_message()
{
	return getInternalMessage_update_mall_stock();
}

/** \fn xmachine_message_update_mall_stock * get_next_update_mall_stock_message(xmachine_message_update_mall_stock * current)
 * \brief Get the next update_mall_stock message in the update_mall_stock message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_update_mall_stock * get_next_update_mall_stock_message(m_update_mall_stock * current)
{
	return getInternalMessage_update_mall_stock();
}


union pu_consumption_request_1 
{
    m_consumption_request_1 *ptr;
    void *ptr_anon;
};

/** \fn void add_consumption_request_1_message(int mall_id, int worker_id, int region_id, int firm_id, double quantity)
 * \brief Add consumption_request_1 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param worker_id Message variable.
 * \param region_id Message variable.
 * \param firm_id Message variable.
 * \param quantity Message variable.
 */
void add_consumption_request_1_message(int mall_id, int worker_id, int region_id, int firm_id, double quantity)
{
    int rc;
	m_consumption_request_1 msg;
    
    msg.mall_id = mall_id;
    msg.worker_id = worker_id;
    msg.region_id = region_id;
    msg.firm_id = firm_id;
    msg.quantity = quantity;
    
    
    rc = MB_AddMessage(b_consumption_request_1, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'consumption_request_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_1' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'consumption_request_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_consumption_request_1* getInternalMessage_consumption_request_1(void)
{
    static m_consumption_request_1 *msg_prev = NULL;
    union pu_consumption_request_1 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_consumption_request_1); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'consumption_request_1' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'consumption_request_1' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_consumption_request_1, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'consumption_request_1' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_1' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_consumption_request_1 * get_first_consumption_request_1_message()
 * \brief Get the first consumption_request_1 message in the consumption_request_1 message list.
 * \return The first message in the list.
 */
m_consumption_request_1 * get_first_consumption_request_1_message()
{
	return getInternalMessage_consumption_request_1();
}

/** \fn xmachine_message_consumption_request_1 * get_next_consumption_request_1_message(xmachine_message_consumption_request_1 * current)
 * \brief Get the next consumption_request_1 message in the consumption_request_1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_consumption_request_1 * get_next_consumption_request_1_message(m_consumption_request_1 * current)
{
	return getInternalMessage_consumption_request_1();
}


union pu_consumption_request_2 
{
    m_consumption_request_2 *ptr;
    void *ptr_anon;
};

/** \fn void add_consumption_request_2_message(int mall_id, int worker_id, int region_id, int firm_id, double quantity)
 * \brief Add consumption_request_2 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param worker_id Message variable.
 * \param region_id Message variable.
 * \param firm_id Message variable.
 * \param quantity Message variable.
 */
void add_consumption_request_2_message(int mall_id, int worker_id, int region_id, int firm_id, double quantity)
{
    int rc;
	m_consumption_request_2 msg;
    
    msg.mall_id = mall_id;
    msg.worker_id = worker_id;
    msg.region_id = region_id;
    msg.firm_id = firm_id;
    msg.quantity = quantity;
    
    
    rc = MB_AddMessage(b_consumption_request_2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'consumption_request_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'consumption_request_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_consumption_request_2* getInternalMessage_consumption_request_2(void)
{
    static m_consumption_request_2 *msg_prev = NULL;
    union pu_consumption_request_2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_consumption_request_2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'consumption_request_2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'consumption_request_2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_consumption_request_2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'consumption_request_2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_consumption_request_2 * get_first_consumption_request_2_message()
 * \brief Get the first consumption_request_2 message in the consumption_request_2 message list.
 * \return The first message in the list.
 */
m_consumption_request_2 * get_first_consumption_request_2_message()
{
	return getInternalMessage_consumption_request_2();
}

/** \fn xmachine_message_consumption_request_2 * get_next_consumption_request_2_message(xmachine_message_consumption_request_2 * current)
 * \brief Get the next consumption_request_2 message in the consumption_request_2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_consumption_request_2 * get_next_consumption_request_2_message(m_consumption_request_2 * current)
{
	return getInternalMessage_consumption_request_2();
}


union pu_accepted_consumption_1 
{
    m_accepted_consumption_1 *ptr;
    void *ptr_anon;
};

/** \fn void add_accepted_consumption_1_message(int mall_id, int household_id, int firm_id, double offered_consumption_volume, int rationed)
 * \brief Add accepted_consumption_1 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param household_id Message variable.
 * \param firm_id Message variable.
 * \param offered_consumption_volume Message variable.
 * \param rationed Message variable.
 */
void add_accepted_consumption_1_message(int mall_id, int household_id, int firm_id, double offered_consumption_volume, int rationed)
{
    int rc;
	m_accepted_consumption_1 msg;
    
    msg.mall_id = mall_id;
    msg.household_id = household_id;
    msg.firm_id = firm_id;
    msg.offered_consumption_volume = offered_consumption_volume;
    msg.rationed = rationed;
    
    
    rc = MB_AddMessage(b_accepted_consumption_1, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'accepted_consumption_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_accepted_consumption_1* getInternalMessage_accepted_consumption_1(void)
{
    static m_accepted_consumption_1 *msg_prev = NULL;
    union pu_accepted_consumption_1 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_accepted_consumption_1); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'accepted_consumption_1' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'accepted_consumption_1' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_accepted_consumption_1, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'accepted_consumption_1' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_accepted_consumption_1 * get_first_accepted_consumption_1_message()
 * \brief Get the first accepted_consumption_1 message in the accepted_consumption_1 message list.
 * \return The first message in the list.
 */
m_accepted_consumption_1 * get_first_accepted_consumption_1_message()
{
	return getInternalMessage_accepted_consumption_1();
}

/** \fn xmachine_message_accepted_consumption_1 * get_next_accepted_consumption_1_message(xmachine_message_accepted_consumption_1 * current)
 * \brief Get the next accepted_consumption_1 message in the accepted_consumption_1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_accepted_consumption_1 * get_next_accepted_consumption_1_message(m_accepted_consumption_1 * current)
{
	return getInternalMessage_accepted_consumption_1();
}


union pu_accepted_consumption_2 
{
    m_accepted_consumption_2 *ptr;
    void *ptr_anon;
};

/** \fn void add_accepted_consumption_2_message(int mall_id, int household_id, int firm_id, double offered_consumption_volume, int rationed)
 * \brief Add accepted_consumption_2 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param household_id Message variable.
 * \param firm_id Message variable.
 * \param offered_consumption_volume Message variable.
 * \param rationed Message variable.
 */
void add_accepted_consumption_2_message(int mall_id, int household_id, int firm_id, double offered_consumption_volume, int rationed)
{
    int rc;
	m_accepted_consumption_2 msg;
    
    msg.mall_id = mall_id;
    msg.household_id = household_id;
    msg.firm_id = firm_id;
    msg.offered_consumption_volume = offered_consumption_volume;
    msg.rationed = rationed;
    
    
    rc = MB_AddMessage(b_accepted_consumption_2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'accepted_consumption_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_accepted_consumption_2* getInternalMessage_accepted_consumption_2(void)
{
    static m_accepted_consumption_2 *msg_prev = NULL;
    union pu_accepted_consumption_2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_accepted_consumption_2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'accepted_consumption_2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'accepted_consumption_2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_accepted_consumption_2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'accepted_consumption_2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_accepted_consumption_2 * get_first_accepted_consumption_2_message()
 * \brief Get the first accepted_consumption_2 message in the accepted_consumption_2 message list.
 * \return The first message in the list.
 */
m_accepted_consumption_2 * get_first_accepted_consumption_2_message()
{
	return getInternalMessage_accepted_consumption_2();
}

/** \fn xmachine_message_accepted_consumption_2 * get_next_accepted_consumption_2_message(xmachine_message_accepted_consumption_2 * current)
 * \brief Get the next accepted_consumption_2 message in the accepted_consumption_2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_accepted_consumption_2 * get_next_accepted_consumption_2_message(m_accepted_consumption_2 * current)
{
	return getInternalMessage_accepted_consumption_2();
}


union pu_sales 
{
    m_sales *ptr;
    void *ptr_anon;
};

/** \fn void add_sales_message(int mall_id, int firm_id, double revenue, int stock_empty, double current_stock)
 * \brief Add sales message by calling internal and processing.
 * \param mall_id Message variable.
 * \param firm_id Message variable.
 * \param revenue Message variable.
 * \param stock_empty Message variable.
 * \param current_stock Message variable.
 */
void add_sales_message(int mall_id, int firm_id, double revenue, int stock_empty, double current_stock)
{
    int rc;
	m_sales msg;
    
    msg.mall_id = mall_id;
    msg.firm_id = firm_id;
    msg.revenue = revenue;
    msg.stock_empty = stock_empty;
    msg.current_stock = current_stock;
    
    
    rc = MB_AddMessage(b_sales, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'sales' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sales' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sales' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_sales* getInternalMessage_sales(void)
{
    static m_sales *msg_prev = NULL;
    union pu_sales msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_sales); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'sales' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'sales' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_sales, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'sales' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sales' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_sales * get_first_sales_message()
 * \brief Get the first sales message in the sales message list.
 * \return The first message in the list.
 */
m_sales * get_first_sales_message()
{
	return getInternalMessage_sales();
}

/** \fn xmachine_message_sales * get_next_sales_message(xmachine_message_sales * current)
 * \brief Get the next sales message in the sales message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_sales * get_next_sales_message(m_sales * current)
{
	return getInternalMessage_sales();
}


union pu_specific_skill_update 
{
    m_specific_skill_update *ptr;
    void *ptr_anon;
};

/** \fn void add_specific_skill_update_message(int id, int firm_id, double specific_skills, int general_skills)
 * \brief Add specific_skill_update message by calling internal and processing.
 * \param id Message variable.
 * \param firm_id Message variable.
 * \param specific_skills Message variable.
 * \param general_skills Message variable.
 */
void add_specific_skill_update_message(int id, int firm_id, double specific_skills, int general_skills)
{
    int rc;
	m_specific_skill_update msg;
    
    msg.id = id;
    msg.firm_id = firm_id;
    msg.specific_skills = specific_skills;
    msg.general_skills = general_skills;
    
    
    rc = MB_AddMessage(b_specific_skill_update, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'specific_skill_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'specific_skill_update' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'specific_skill_update' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_specific_skill_update* getInternalMessage_specific_skill_update(void)
{
    static m_specific_skill_update *msg_prev = NULL;
    union pu_specific_skill_update msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_specific_skill_update); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'specific_skill_update' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'specific_skill_update' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_specific_skill_update, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'specific_skill_update' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'specific_skill_update' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_specific_skill_update * get_first_specific_skill_update_message()
 * \brief Get the first specific_skill_update message in the specific_skill_update message list.
 * \return The first message in the list.
 */
m_specific_skill_update * get_first_specific_skill_update_message()
{
	return getInternalMessage_specific_skill_update();
}

/** \fn xmachine_message_specific_skill_update * get_next_specific_skill_update_message(xmachine_message_specific_skill_update * current)
 * \brief Get the next specific_skill_update message in the specific_skill_update message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_specific_skill_update * get_next_specific_skill_update_message(m_specific_skill_update * current)
{
	return getInternalMessage_specific_skill_update();
}


union pu_policy_rate 
{
    m_policy_rate *ptr;
    void *ptr_anon;
};

/** \fn void add_policy_rate_message(double policy_rate_value)
 * \brief Add policy_rate message by calling internal and processing.
 * \param policy_rate_value Message variable.
 */
void add_policy_rate_message(double policy_rate_value)
{
    int rc;
	m_policy_rate msg;
    
    msg.policy_rate_value = policy_rate_value;
    
    
    rc = MB_AddMessage(b_policy_rate, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'policy_rate' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'policy_rate' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'policy_rate' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_policy_rate* getInternalMessage_policy_rate(void)
{
    static m_policy_rate *msg_prev = NULL;
    union pu_policy_rate msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_policy_rate); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'policy_rate' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'policy_rate' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_policy_rate, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'policy_rate' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'policy_rate' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_policy_rate * get_first_policy_rate_message()
 * \brief Get the first policy_rate message in the policy_rate message list.
 * \return The first message in the list.
 */
m_policy_rate * get_first_policy_rate_message()
{
	return getInternalMessage_policy_rate();
}

/** \fn xmachine_message_policy_rate * get_next_policy_rate_message(xmachine_message_policy_rate * current)
 * \brief Get the next policy_rate message in the policy_rate message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_policy_rate * get_next_policy_rate_message(m_policy_rate * current)
{
	return getInternalMessage_policy_rate();
}


union pu_bank_identity 
{
    m_bank_identity *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_identity_message(int bank_id)
 * \brief Add bank_identity message by calling internal and processing.
 * \param bank_id Message variable.
 */
void add_bank_identity_message(int bank_id)
{
    int rc;
	m_bank_identity msg;
    
    msg.bank_id = bank_id;
    
    
    rc = MB_AddMessage(b_bank_identity, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_identity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_identity' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_identity' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_identity* getInternalMessage_bank_identity(void)
{
    static m_bank_identity *msg_prev = NULL;
    union pu_bank_identity msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_identity); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_identity' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_identity' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_identity, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_identity' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_identity' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_identity * get_first_bank_identity_message()
 * \brief Get the first bank_identity message in the bank_identity message list.
 * \return The first message in the list.
 */
m_bank_identity * get_first_bank_identity_message()
{
	return getInternalMessage_bank_identity();
}

/** \fn xmachine_message_bank_identity * get_next_bank_identity_message(xmachine_message_bank_identity * current)
 * \brief Get the next bank_identity message in the bank_identity message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_identity * get_next_bank_identity_message(m_bank_identity * current)
{
	return getInternalMessage_bank_identity();
}


union pu_loan_request 
{
    m_loan_request *ptr;
    void *ptr_anon;
};

/** \fn void add_loan_request_message(int firm_id, int bank_id, double equity, double total_debt, double external_financial_needs)
 * \brief Add loan_request message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param equity Message variable.
 * \param total_debt Message variable.
 * \param external_financial_needs Message variable.
 */
void add_loan_request_message(int firm_id, int bank_id, double equity, double total_debt, double external_financial_needs)
{
    int rc;
	m_loan_request msg;
    
    msg.firm_id = firm_id;
    msg.bank_id = bank_id;
    msg.equity = equity;
    msg.total_debt = total_debt;
    msg.external_financial_needs = external_financial_needs;
    
    
    rc = MB_AddMessage(b_loan_request, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'loan_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_loan_request* getInternalMessage_loan_request(void)
{
    static m_loan_request *msg_prev = NULL;
    union pu_loan_request msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_loan_request); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'loan_request' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'loan_request' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_loan_request, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'loan_request' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_loan_request * get_first_loan_request_message()
 * \brief Get the first loan_request message in the loan_request message list.
 * \return The first message in the list.
 */
m_loan_request * get_first_loan_request_message()
{
	return getInternalMessage_loan_request();
}

/** \fn xmachine_message_loan_request * get_next_loan_request_message(xmachine_message_loan_request * current)
 * \brief Get the next loan_request message in the loan_request message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_loan_request * get_next_loan_request_message(m_loan_request * current)
{
	return getInternalMessage_loan_request();
}


union pu_loan_request_ranked 
{
    m_loan_request_ranked *ptr;
    void *ptr_anon;
};

/** \fn void add_loan_request_ranked_message(int firm_id, int bank_id, double equity, double total_debt, double credit_request, double value_at_risk_request)
 * \brief Add loan_request_ranked message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param equity Message variable.
 * \param total_debt Message variable.
 * \param credit_request Message variable.
 * \param value_at_risk_request Message variable.
 */
void add_loan_request_ranked_message(int firm_id, int bank_id, double equity, double total_debt, double credit_request, double value_at_risk_request)
{
    int rc;
	m_loan_request_ranked msg;
    
    msg.firm_id = firm_id;
    msg.bank_id = bank_id;
    msg.equity = equity;
    msg.total_debt = total_debt;
    msg.credit_request = credit_request;
    msg.value_at_risk_request = value_at_risk_request;
    
    
    rc = MB_AddMessage(b_loan_request_ranked, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'loan_request_ranked' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request_ranked' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_request_ranked' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_loan_request_ranked* getInternalMessage_loan_request_ranked(void)
{
    static m_loan_request_ranked *msg_prev = NULL;
    union pu_loan_request_ranked msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_loan_request_ranked); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'loan_request_ranked' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'loan_request_ranked' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_loan_request_ranked, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'loan_request_ranked' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request_ranked' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_loan_request_ranked * get_first_loan_request_ranked_message()
 * \brief Get the first loan_request_ranked message in the loan_request_ranked message list.
 * \return The first message in the list.
 */
m_loan_request_ranked * get_first_loan_request_ranked_message()
{
	return getInternalMessage_loan_request_ranked();
}

/** \fn xmachine_message_loan_request_ranked * get_next_loan_request_ranked_message(xmachine_message_loan_request_ranked * current)
 * \brief Get the next loan_request_ranked message in the loan_request_ranked message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_loan_request_ranked * get_next_loan_request_ranked_message(m_loan_request_ranked * current)
{
	return getInternalMessage_loan_request_ranked();
}


union pu_loan_conditions 
{
    m_loan_conditions *ptr;
    void *ptr_anon;
};

/** \fn void add_loan_conditions_message(int firm_id, int bank_id, double proposed_interest_rate, double amount_offered_credit, double value_at_risk)
 * \brief Add loan_conditions message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param proposed_interest_rate Message variable.
 * \param amount_offered_credit Message variable.
 * \param value_at_risk Message variable.
 */
void add_loan_conditions_message(int firm_id, int bank_id, double proposed_interest_rate, double amount_offered_credit, double value_at_risk)
{
    int rc;
	m_loan_conditions msg;
    
    msg.firm_id = firm_id;
    msg.bank_id = bank_id;
    msg.proposed_interest_rate = proposed_interest_rate;
    msg.amount_offered_credit = amount_offered_credit;
    msg.value_at_risk = value_at_risk;
    
    
    rc = MB_AddMessage(b_loan_conditions, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'loan_conditions' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_conditions' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_conditions' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_loan_conditions* getInternalMessage_loan_conditions(void)
{
    static m_loan_conditions *msg_prev = NULL;
    union pu_loan_conditions msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_loan_conditions); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'loan_conditions' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'loan_conditions' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_loan_conditions, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'loan_conditions' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_conditions' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_loan_conditions * get_first_loan_conditions_message()
 * \brief Get the first loan_conditions message in the loan_conditions message list.
 * \return The first message in the list.
 */
m_loan_conditions * get_first_loan_conditions_message()
{
	return getInternalMessage_loan_conditions();
}

/** \fn xmachine_message_loan_conditions * get_next_loan_conditions_message(xmachine_message_loan_conditions * current)
 * \brief Get the next loan_conditions message in the loan_conditions message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_loan_conditions * get_next_loan_conditions_message(m_loan_conditions * current)
{
	return getInternalMessage_loan_conditions();
}


union pu_loan_acceptance 
{
    m_loan_acceptance *ptr;
    void *ptr_anon;
};

/** \fn void add_loan_acceptance_message(int bank_id, double credit_amount_taken, double loan_total_var, double interest_rate)
 * \brief Add loan_acceptance message by calling internal and processing.
 * \param bank_id Message variable.
 * \param credit_amount_taken Message variable.
 * \param loan_total_var Message variable.
 * \param interest_rate Message variable.
 */
void add_loan_acceptance_message(int bank_id, double credit_amount_taken, double loan_total_var, double interest_rate)
{
    int rc;
	m_loan_acceptance msg;
    
    msg.bank_id = bank_id;
    msg.credit_amount_taken = credit_amount_taken;
    msg.loan_total_var = loan_total_var;
    msg.interest_rate = interest_rate;
    
    
    rc = MB_AddMessage(b_loan_acceptance, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'loan_acceptance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acceptance' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_acceptance' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_loan_acceptance* getInternalMessage_loan_acceptance(void)
{
    static m_loan_acceptance *msg_prev = NULL;
    union pu_loan_acceptance msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_loan_acceptance); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'loan_acceptance' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'loan_acceptance' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_loan_acceptance, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'loan_acceptance' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acceptance' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_loan_acceptance * get_first_loan_acceptance_message()
 * \brief Get the first loan_acceptance message in the loan_acceptance message list.
 * \return The first message in the list.
 */
m_loan_acceptance * get_first_loan_acceptance_message()
{
	return getInternalMessage_loan_acceptance();
}

/** \fn xmachine_message_loan_acceptance * get_next_loan_acceptance_message(xmachine_message_loan_acceptance * current)
 * \brief Get the next loan_acceptance message in the loan_acceptance message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_loan_acceptance * get_next_loan_acceptance_message(m_loan_acceptance * current)
{
	return getInternalMessage_loan_acceptance();
}


union pu_installment 
{
    m_installment *ptr;
    void *ptr_anon;
};

/** \fn void add_installment_message(int bank_id, double installment_amount, double interest_amount, double var_per_installment, double total_var)
 * \brief Add installment message by calling internal and processing.
 * \param bank_id Message variable.
 * \param installment_amount Message variable.
 * \param interest_amount Message variable.
 * \param var_per_installment Message variable.
 * \param total_var Message variable.
 */
void add_installment_message(int bank_id, double installment_amount, double interest_amount, double var_per_installment, double total_var)
{
    int rc;
	m_installment msg;
    
    msg.bank_id = bank_id;
    msg.installment_amount = installment_amount;
    msg.interest_amount = interest_amount;
    msg.var_per_installment = var_per_installment;
    msg.total_var = total_var;
    
    
    rc = MB_AddMessage(b_installment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'installment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'installment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'installment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_installment* getInternalMessage_installment(void)
{
    static m_installment *msg_prev = NULL;
    union pu_installment msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_installment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'installment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'installment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_installment, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'installment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'installment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_installment * get_first_installment_message()
 * \brief Get the first installment message in the installment message list.
 * \return The first message in the list.
 */
m_installment * get_first_installment_message()
{
	return getInternalMessage_installment();
}

/** \fn xmachine_message_installment * get_next_installment_message(xmachine_message_installment * current)
 * \brief Get the next installment message in the installment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_installment * get_next_installment_message(m_installment * current)
{
	return getInternalMessage_installment();
}


union pu_bankruptcy 
{
    m_bankruptcy *ptr;
    void *ptr_anon;
};

/** \fn void add_bankruptcy_message(int firm_id, int bank_id, double bad_debt, double credit_refunded, double writeoff_var)
 * \brief Add bankruptcy message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param bad_debt Message variable.
 * \param credit_refunded Message variable.
 * \param writeoff_var Message variable.
 */
void add_bankruptcy_message(int firm_id, int bank_id, double bad_debt, double credit_refunded, double writeoff_var)
{
    int rc;
	m_bankruptcy msg;
    
    msg.firm_id = firm_id;
    msg.bank_id = bank_id;
    msg.bad_debt = bad_debt;
    msg.credit_refunded = credit_refunded;
    msg.writeoff_var = writeoff_var;
    
    
    rc = MB_AddMessage(b_bankruptcy, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bankruptcy' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bankruptcy* getInternalMessage_bankruptcy(void)
{
    static m_bankruptcy *msg_prev = NULL;
    union pu_bankruptcy msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bankruptcy); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bankruptcy' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bankruptcy' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bankruptcy, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bankruptcy' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bankruptcy * get_first_bankruptcy_message()
 * \brief Get the first bankruptcy message in the bankruptcy message list.
 * \return The first message in the list.
 */
m_bankruptcy * get_first_bankruptcy_message()
{
	return getInternalMessage_bankruptcy();
}

/** \fn xmachine_message_bankruptcy * get_next_bankruptcy_message(xmachine_message_bankruptcy * current)
 * \brief Get the next bankruptcy message in the bankruptcy message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bankruptcy * get_next_bankruptcy_message(m_bankruptcy * current)
{
	return getInternalMessage_bankruptcy();
}


union pu_bank_interest_payment 
{
    m_bank_interest_payment *ptr;
    void *ptr_anon;
};

/** \fn void add_bank_interest_payment_message(double bank_interest_amount)
 * \brief Add bank_interest_payment message by calling internal and processing.
 * \param bank_interest_amount Message variable.
 */
void add_bank_interest_payment_message(double bank_interest_amount)
{
    int rc;
	m_bank_interest_payment msg;
    
    msg.bank_interest_amount = bank_interest_amount;
    
    
    rc = MB_AddMessage(b_bank_interest_payment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_interest_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_interest_payment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_interest_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_interest_payment* getInternalMessage_bank_interest_payment(void)
{
    static m_bank_interest_payment *msg_prev = NULL;
    union pu_bank_interest_payment msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_interest_payment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_interest_payment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_interest_payment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_interest_payment, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_interest_payment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_interest_payment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bank_interest_payment * get_first_bank_interest_payment_message()
 * \brief Get the first bank_interest_payment message in the bank_interest_payment message list.
 * \return The first message in the list.
 */
m_bank_interest_payment * get_first_bank_interest_payment_message()
{
	return getInternalMessage_bank_interest_payment();
}

/** \fn xmachine_message_bank_interest_payment * get_next_bank_interest_payment_message(xmachine_message_bank_interest_payment * current)
 * \brief Get the next bank_interest_payment message in the bank_interest_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_interest_payment * get_next_bank_interest_payment_message(m_bank_interest_payment * current)
{
	return getInternalMessage_bank_interest_payment();
}


union pu_account_interest 
{
    m_account_interest *ptr;
    void *ptr_anon;
};

/** \fn void add_account_interest_message(int bank_id, double interest_rate)
 * \brief Add account_interest message by calling internal and processing.
 * \param bank_id Message variable.
 * \param interest_rate Message variable.
 */
void add_account_interest_message(int bank_id, double interest_rate)
{
    int rc;
	m_account_interest msg;
    
    msg.bank_id = bank_id;
    msg.interest_rate = interest_rate;
    
    
    rc = MB_AddMessage(b_account_interest, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'account_interest' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'account_interest' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'account_interest' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_account_interest* getInternalMessage_account_interest(void)
{
    static m_account_interest *msg_prev = NULL;
    union pu_account_interest msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_account_interest); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'account_interest' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'account_interest' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_account_interest, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'account_interest' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'account_interest' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_account_interest * get_first_account_interest_message()
 * \brief Get the first account_interest message in the account_interest message list.
 * \return The first message in the list.
 */
m_account_interest * get_first_account_interest_message()
{
	return getInternalMessage_account_interest();
}

/** \fn xmachine_message_account_interest * get_next_account_interest_message(xmachine_message_account_interest * current)
 * \brief Get the next account_interest message in the account_interest message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_account_interest * get_next_account_interest_message(m_account_interest * current)
{
	return getInternalMessage_account_interest();
}


union pu_ecb_dividend 
{
    m_ecb_dividend *ptr;
    void *ptr_anon;
};

/** \fn void add_ecb_dividend_message(int gov_id, double dividend_per_gov)
 * \brief Add ecb_dividend message by calling internal and processing.
 * \param gov_id Message variable.
 * \param dividend_per_gov Message variable.
 */
void add_ecb_dividend_message(int gov_id, double dividend_per_gov)
{
    int rc;
	m_ecb_dividend msg;
    
    msg.gov_id = gov_id;
    msg.dividend_per_gov = dividend_per_gov;
    
    
    rc = MB_AddMessage(b_ecb_dividend, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'ecb_dividend' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'ecb_dividend' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'ecb_dividend' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_ecb_dividend* getInternalMessage_ecb_dividend(void)
{
    static m_ecb_dividend *msg_prev = NULL;
    union pu_ecb_dividend msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_ecb_dividend); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'ecb_dividend' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'ecb_dividend' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_ecb_dividend, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'ecb_dividend' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'ecb_dividend' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_ecb_dividend * get_first_ecb_dividend_message()
 * \brief Get the first ecb_dividend message in the ecb_dividend message list.
 * \return The first message in the list.
 */
m_ecb_dividend * get_first_ecb_dividend_message()
{
	return getInternalMessage_ecb_dividend();
}

/** \fn xmachine_message_ecb_dividend * get_next_ecb_dividend_message(xmachine_message_ecb_dividend * current)
 * \brief Get the next ecb_dividend message in the ecb_dividend message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_ecb_dividend * get_next_ecb_dividend_message(m_ecb_dividend * current)
{
	return getInternalMessage_ecb_dividend();
}


union pu_credit_var_update 
{
    m_credit_var_update *ptr;
    void *ptr_anon;
};

/** \fn void add_credit_var_update_message(int firm_id, int bank_id, double value_at_risk)
 * \brief Add credit_var_update message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param value_at_risk Message variable.
 */
void add_credit_var_update_message(int firm_id, int bank_id, double value_at_risk)
{
    int rc;
	m_credit_var_update msg;
    
    msg.firm_id = firm_id;
    msg.bank_id = bank_id;
    msg.value_at_risk = value_at_risk;
    
    
    rc = MB_AddMessage(b_credit_var_update, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'credit_var_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'credit_var_update' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'credit_var_update' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_credit_var_update* getInternalMessage_credit_var_update(void)
{
    static m_credit_var_update *msg_prev = NULL;
    union pu_credit_var_update msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_credit_var_update); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'credit_var_update' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'credit_var_update' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_credit_var_update, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'credit_var_update' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'credit_var_update' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_credit_var_update * get_first_credit_var_update_message()
 * \brief Get the first credit_var_update message in the credit_var_update message list.
 * \return The first message in the list.
 */
m_credit_var_update * get_first_credit_var_update_message()
{
	return getInternalMessage_credit_var_update();
}

/** \fn xmachine_message_credit_var_update * get_next_credit_var_update_message(xmachine_message_credit_var_update * current)
 * \brief Get the next credit_var_update message in the credit_var_update message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_credit_var_update * get_next_credit_var_update_message(m_credit_var_update * current)
{
	return getInternalMessage_credit_var_update();
}


union pu_bankruptcy_illiquidity 
{
    m_bankruptcy_illiquidity *ptr;
    void *ptr_anon;
};

/** \fn void add_bankruptcy_illiquidity_message(int firm_id)
 * \brief Add bankruptcy_illiquidity message by calling internal and processing.
 * \param firm_id Message variable.
 */
void add_bankruptcy_illiquidity_message(int firm_id)
{
    int rc;
	m_bankruptcy_illiquidity msg;
    
    msg.firm_id = firm_id;
    
    
    rc = MB_AddMessage(b_bankruptcy_illiquidity, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bankruptcy_illiquidity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bankruptcy_illiquidity* getInternalMessage_bankruptcy_illiquidity(void)
{
    static m_bankruptcy_illiquidity *msg_prev = NULL;
    union pu_bankruptcy_illiquidity msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bankruptcy_illiquidity); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bankruptcy_illiquidity' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bankruptcy_illiquidity, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bankruptcy_illiquidity' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bankruptcy_illiquidity * get_first_bankruptcy_illiquidity_message()
 * \brief Get the first bankruptcy_illiquidity message in the bankruptcy_illiquidity message list.
 * \return The first message in the list.
 */
m_bankruptcy_illiquidity * get_first_bankruptcy_illiquidity_message()
{
	return getInternalMessage_bankruptcy_illiquidity();
}

/** \fn xmachine_message_bankruptcy_illiquidity * get_next_bankruptcy_illiquidity_message(xmachine_message_bankruptcy_illiquidity * current)
 * \brief Get the next bankruptcy_illiquidity message in the bankruptcy_illiquidity message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bankruptcy_illiquidity * get_next_bankruptcy_illiquidity_message(m_bankruptcy_illiquidity * current)
{
	return getInternalMessage_bankruptcy_illiquidity();
}


union pu_bankruptcy_insolvency 
{
    m_bankruptcy_insolvency *ptr;
    void *ptr_anon;
};

/** \fn void add_bankruptcy_insolvency_message(int firm_id)
 * \brief Add bankruptcy_insolvency message by calling internal and processing.
 * \param firm_id Message variable.
 */
void add_bankruptcy_insolvency_message(int firm_id)
{
    int rc;
	m_bankruptcy_insolvency msg;
    
    msg.firm_id = firm_id;
    
    
    rc = MB_AddMessage(b_bankruptcy_insolvency, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bankruptcy_insolvency' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bankruptcy_insolvency* getInternalMessage_bankruptcy_insolvency(void)
{
    static m_bankruptcy_insolvency *msg_prev = NULL;
    union pu_bankruptcy_insolvency msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bankruptcy_insolvency); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bankruptcy_insolvency' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bankruptcy_insolvency' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bankruptcy_insolvency, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bankruptcy_insolvency' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_bankruptcy_insolvency * get_first_bankruptcy_insolvency_message()
 * \brief Get the first bankruptcy_insolvency message in the bankruptcy_insolvency message list.
 * \return The first message in the list.
 */
m_bankruptcy_insolvency * get_first_bankruptcy_insolvency_message()
{
	return getInternalMessage_bankruptcy_insolvency();
}

/** \fn xmachine_message_bankruptcy_insolvency * get_next_bankruptcy_insolvency_message(xmachine_message_bankruptcy_insolvency * current)
 * \brief Get the next bankruptcy_insolvency message in the bankruptcy_insolvency message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bankruptcy_insolvency * get_next_bankruptcy_insolvency_message(m_bankruptcy_insolvency * current)
{
	return getInternalMessage_bankruptcy_insolvency();
}


union pu_index_info 
{
    m_index_info *ptr;
    void *ptr_anon;
};

/** \fn void add_index_info_message(double dividend_per_share)
 * \brief Add index_info message by calling internal and processing.
 * \param dividend_per_share Message variable.
 */
void add_index_info_message(double dividend_per_share)
{
    int rc;
	m_index_info msg;
    
    msg.dividend_per_share = dividend_per_share;
    
    
    rc = MB_AddMessage(b_index_info, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'index_info' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'index_info' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'index_info' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_index_info* getInternalMessage_index_info(void)
{
    static m_index_info *msg_prev = NULL;
    union pu_index_info msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_index_info); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'index_info' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'index_info' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_index_info, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'index_info' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'index_info' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_index_info * get_first_index_info_message()
 * \brief Get the first index_info message in the index_info message list.
 * \return The first message in the list.
 */
m_index_info * get_first_index_info_message()
{
	return getInternalMessage_index_info();
}

/** \fn xmachine_message_index_info * get_next_index_info_message(xmachine_message_index_info * current)
 * \brief Get the next index_info message in the index_info message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_index_info * get_next_index_info_message(m_index_info * current)
{
	return getInternalMessage_index_info();
}


union pu_index_price 
{
    m_index_price *ptr;
    void *ptr_anon;
};

/** \fn void add_index_price_message(double price, double moving_avg_price)
 * \brief Add index_price message by calling internal and processing.
 * \param price Message variable.
 * \param moving_avg_price Message variable.
 */
void add_index_price_message(double price, double moving_avg_price)
{
    int rc;
	m_index_price msg;
    
    msg.price = price;
    msg.moving_avg_price = moving_avg_price;
    
    
    rc = MB_AddMessage(b_index_price, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'index_price' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'index_price' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'index_price' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_index_price* getInternalMessage_index_price(void)
{
    static m_index_price *msg_prev = NULL;
    union pu_index_price msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_index_price); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'index_price' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'index_price' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_index_price, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'index_price' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'index_price' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_index_price * get_first_index_price_message()
 * \brief Get the first index_price message in the index_price message list.
 * \return The first message in the list.
 */
m_index_price * get_first_index_price_message()
{
	return getInternalMessage_index_price();
}

/** \fn xmachine_message_index_price * get_next_index_price_message(xmachine_message_index_price * current)
 * \brief Get the next index_price message in the index_price message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_index_price * get_next_index_price_message(m_index_price * current)
{
	return getInternalMessage_index_price();
}


union pu_order 
{
    m_order *ptr;
    void *ptr_anon;
};

/** \fn void add_order_message(int trader_id, double value)
 * \brief Add order message by calling internal and processing.
 * \param trader_id Message variable.
 * \param value Message variable.
 */
void add_order_message(int trader_id, double value)
{
    int rc;
	m_order msg;
    
    msg.trader_id = trader_id;
    msg.value = value;
    
    
    rc = MB_AddMessage(b_order, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'order' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'order' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_order* getInternalMessage_order(void)
{
    static m_order *msg_prev = NULL;
    union pu_order msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_order); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'order' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'order' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_order, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'order' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_order * get_first_order_message()
 * \brief Get the first order message in the order message list.
 * \return The first message in the list.
 */
m_order * get_first_order_message()
{
	return getInternalMessage_order();
}

/** \fn xmachine_message_order * get_next_order_message(xmachine_message_order * current)
 * \brief Get the next order message in the order message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_order * get_next_order_message(m_order * current)
{
	return getInternalMessage_order();
}


union pu_order_status 
{
    m_order_status *ptr;
    void *ptr_anon;
};

/** \fn void add_order_status_message(int trader_id, double value, int quantity)
 * \brief Add order_status message by calling internal and processing.
 * \param trader_id Message variable.
 * \param value Message variable.
 * \param quantity Message variable.
 */
void add_order_status_message(int trader_id, double value, int quantity)
{
    int rc;
	m_order_status msg;
    
    msg.trader_id = trader_id;
    msg.value = value;
    msg.quantity = quantity;
    
    
    rc = MB_AddMessage(b_order_status, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'order_status' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order_status' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'order_status' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_order_status* getInternalMessage_order_status(void)
{
    static m_order_status *msg_prev = NULL;
    union pu_order_status msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_order_status); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'order_status' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'order_status' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_order_status, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'order_status' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order_status' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_order_status * get_first_order_status_message()
 * \brief Get the first order_status message in the order_status message list.
 * \return The first message in the list.
 */
m_order_status * get_first_order_status_message()
{
	return getInternalMessage_order_status();
}

/** \fn xmachine_message_order_status * get_next_order_status_message(xmachine_message_order_status * current)
 * \brief Get the next order_status message in the order_status message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_order_status * get_next_order_status_message(m_order_status * current)
{
	return getInternalMessage_order_status();
}


union pu_dividend_info 
{
    m_dividend_info *ptr;
    void *ptr_anon;
};

/** \fn void add_dividend_info_message(int firm_id, double total_dividend)
 * \brief Add dividend_info message by calling internal and processing.
 * \param firm_id Message variable.
 * \param total_dividend Message variable.
 */
void add_dividend_info_message(int firm_id, double total_dividend)
{
    int rc;
	m_dividend_info msg;
    
    msg.firm_id = firm_id;
    msg.total_dividend = total_dividend;
    
    
    rc = MB_AddMessage(b_dividend_info, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'dividend_info' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend_info' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'dividend_info' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_dividend_info* getInternalMessage_dividend_info(void)
{
    static m_dividend_info *msg_prev = NULL;
    union pu_dividend_info msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_dividend_info); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'dividend_info' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'dividend_info' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_dividend_info, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'dividend_info' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend_info' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_dividend_info * get_first_dividend_info_message()
 * \brief Get the first dividend_info message in the dividend_info message list.
 * \return The first message in the list.
 */
m_dividend_info * get_first_dividend_info_message()
{
	return getInternalMessage_dividend_info();
}

/** \fn xmachine_message_dividend_info * get_next_dividend_info_message(xmachine_message_dividend_info * current)
 * \brief Get the next dividend_info message in the dividend_info message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_dividend_info * get_next_dividend_info_message(m_dividend_info * current)
{
	return getInternalMessage_dividend_info();
}


union pu_productivity 
{
    m_productivity *ptr;
    void *ptr_anon;
};

/** \fn void add_productivity_message(int IGfirm_id, double cap_productivity, double cap_good_price)
 * \brief Add productivity message by calling internal and processing.
 * \param IGfirm_id Message variable.
 * \param cap_productivity Message variable.
 * \param cap_good_price Message variable.
 */
void add_productivity_message(int IGfirm_id, double cap_productivity, double cap_good_price)
{
    int rc;
	m_productivity msg;
    
    msg.IGfirm_id = IGfirm_id;
    msg.cap_productivity = cap_productivity;
    msg.cap_good_price = cap_good_price;
    
    
    rc = MB_AddMessage(b_productivity, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'productivity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'productivity' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'productivity' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_productivity* getInternalMessage_productivity(void)
{
    static m_productivity *msg_prev = NULL;
    union pu_productivity msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_productivity); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'productivity' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'productivity' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_productivity, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'productivity' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'productivity' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_productivity * get_first_productivity_message()
 * \brief Get the first productivity message in the productivity message list.
 * \return The first message in the list.
 */
m_productivity * get_first_productivity_message()
{
	return getInternalMessage_productivity();
}

/** \fn xmachine_message_productivity * get_next_productivity_message(xmachine_message_productivity * current)
 * \brief Get the next productivity message in the productivity message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_productivity * get_next_productivity_message(m_productivity * current)
{
	return getInternalMessage_productivity();
}


union pu_capital_good_request 
{
    m_capital_good_request *ptr;
    void *ptr_anon;
};

/** \fn void add_capital_good_request_message(int firm_id, double capital_good_demand, int vintage)
 * \brief Add capital_good_request message by calling internal and processing.
 * \param firm_id Message variable.
 * \param capital_good_demand Message variable.
 * \param vintage Message variable.
 */
void add_capital_good_request_message(int firm_id, double capital_good_demand, int vintage)
{
    int rc;
	m_capital_good_request msg;
    
    msg.firm_id = firm_id;
    msg.capital_good_demand = capital_good_demand;
    msg.vintage = vintage;
    
    
    rc = MB_AddMessage(b_capital_good_request, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'capital_good_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_request' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_capital_good_request* getInternalMessage_capital_good_request(void)
{
    static m_capital_good_request *msg_prev = NULL;
    union pu_capital_good_request msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_capital_good_request); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'capital_good_request' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'capital_good_request' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_capital_good_request, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'capital_good_request' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_request' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_capital_good_request * get_first_capital_good_request_message()
 * \brief Get the first capital_good_request message in the capital_good_request message list.
 * \return The first message in the list.
 */
m_capital_good_request * get_first_capital_good_request_message()
{
	return getInternalMessage_capital_good_request();
}

/** \fn xmachine_message_capital_good_request * get_next_capital_good_request_message(xmachine_message_capital_good_request * current)
 * \brief Get the next capital_good_request message in the capital_good_request message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_capital_good_request * get_next_capital_good_request_message(m_capital_good_request * current)
{
	return getInternalMessage_capital_good_request();
}


union pu_capital_good_delivery 
{
    m_capital_good_delivery *ptr;
    void *ptr_anon;
};

/** \fn void add_capital_good_delivery_message(int firm_id, double capital_good_delivery_volume, double productivity, double capital_good_price)
 * \brief Add capital_good_delivery message by calling internal and processing.
 * \param firm_id Message variable.
 * \param capital_good_delivery_volume Message variable.
 * \param productivity Message variable.
 * \param capital_good_price Message variable.
 */
void add_capital_good_delivery_message(int firm_id, double capital_good_delivery_volume, double productivity, double capital_good_price)
{
    int rc;
	m_capital_good_delivery msg;
    
    msg.firm_id = firm_id;
    msg.capital_good_delivery_volume = capital_good_delivery_volume;
    msg.productivity = productivity;
    msg.capital_good_price = capital_good_price;
    
    
    rc = MB_AddMessage(b_capital_good_delivery, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'capital_good_delivery' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_delivery' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_delivery' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_capital_good_delivery* getInternalMessage_capital_good_delivery(void)
{
    static m_capital_good_delivery *msg_prev = NULL;
    union pu_capital_good_delivery msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_capital_good_delivery); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'capital_good_delivery' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'capital_good_delivery' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_capital_good_delivery, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'capital_good_delivery' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_delivery' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_capital_good_delivery * get_first_capital_good_delivery_message()
 * \brief Get the first capital_good_delivery message in the capital_good_delivery message list.
 * \return The first message in the list.
 */
m_capital_good_delivery * get_first_capital_good_delivery_message()
{
	return getInternalMessage_capital_good_delivery();
}

/** \fn xmachine_message_capital_good_delivery * get_next_capital_good_delivery_message(xmachine_message_capital_good_delivery * current)
 * \brief Get the next capital_good_delivery message in the capital_good_delivery message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_capital_good_delivery * get_next_capital_good_delivery_message(m_capital_good_delivery * current)
{
	return getInternalMessage_capital_good_delivery();
}


union pu_pay_capital_goods 
{
    m_pay_capital_goods *ptr;
    void *ptr_anon;
};

/** \fn void add_pay_capital_goods_message(int firm_id, double capital_bill)
 * \brief Add pay_capital_goods message by calling internal and processing.
 * \param firm_id Message variable.
 * \param capital_bill Message variable.
 */
void add_pay_capital_goods_message(int firm_id, double capital_bill)
{
    int rc;
	m_pay_capital_goods msg;
    
    msg.firm_id = firm_id;
    msg.capital_bill = capital_bill;
    
    
    rc = MB_AddMessage(b_pay_capital_goods, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'pay_capital_goods' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pay_capital_goods' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pay_capital_goods' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_pay_capital_goods* getInternalMessage_pay_capital_goods(void)
{
    static m_pay_capital_goods *msg_prev = NULL;
    union pu_pay_capital_goods msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_pay_capital_goods); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'pay_capital_goods' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'pay_capital_goods' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_pay_capital_goods, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'pay_capital_goods' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pay_capital_goods' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_pay_capital_goods * get_first_pay_capital_goods_message()
 * \brief Get the first pay_capital_goods message in the pay_capital_goods message list.
 * \return The first message in the list.
 */
m_pay_capital_goods * get_first_pay_capital_goods_message()
{
	return getInternalMessage_pay_capital_goods();
}

/** \fn xmachine_message_pay_capital_goods * get_next_pay_capital_goods_message(xmachine_message_pay_capital_goods * current)
 * \brief Get the next pay_capital_goods message in the pay_capital_goods message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_pay_capital_goods * get_next_pay_capital_goods_message(m_pay_capital_goods * current)
{
	return getInternalMessage_pay_capital_goods();
}


union pu_vacancies 
{
    m_vacancies *ptr;
    void *ptr_anon;
};

/** \fn void add_vacancies_message(int firm_id, int region_id, double firm_wage_offer_for_skill_1, double firm_wage_offer_for_skill_2, double firm_wage_offer_for_skill_3, double firm_wage_offer_for_skill_4, double firm_wage_offer_for_skill_5)
 * \brief Add vacancies message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param firm_wage_offer_for_skill_1 Message variable.
 * \param firm_wage_offer_for_skill_2 Message variable.
 * \param firm_wage_offer_for_skill_3 Message variable.
 * \param firm_wage_offer_for_skill_4 Message variable.
 * \param firm_wage_offer_for_skill_5 Message variable.
 */
void add_vacancies_message(int firm_id, int region_id, double firm_wage_offer_for_skill_1, double firm_wage_offer_for_skill_2, double firm_wage_offer_for_skill_3, double firm_wage_offer_for_skill_4, double firm_wage_offer_for_skill_5)
{
    int rc;
	m_vacancies msg;
    
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.firm_wage_offer_for_skill_1 = firm_wage_offer_for_skill_1;
    msg.firm_wage_offer_for_skill_2 = firm_wage_offer_for_skill_2;
    msg.firm_wage_offer_for_skill_3 = firm_wage_offer_for_skill_3;
    msg.firm_wage_offer_for_skill_4 = firm_wage_offer_for_skill_4;
    msg.firm_wage_offer_for_skill_5 = firm_wage_offer_for_skill_5;
    
    
    rc = MB_AddMessage(b_vacancies, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'vacancies' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancies' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_vacancies* getInternalMessage_vacancies(void)
{
    static m_vacancies *msg_prev = NULL;
    union pu_vacancies msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_vacancies); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'vacancies' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'vacancies' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_vacancies, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'vacancies' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_vacancies * get_first_vacancies_message()
 * \brief Get the first vacancies message in the vacancies message list.
 * \return The first message in the list.
 */
m_vacancies * get_first_vacancies_message()
{
	return getInternalMessage_vacancies();
}

/** \fn xmachine_message_vacancies * get_next_vacancies_message(xmachine_message_vacancies * current)
 * \brief Get the next vacancies message in the vacancies message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_vacancies * get_next_vacancies_message(m_vacancies * current)
{
	return getInternalMessage_vacancies();
}


union pu_vacancies2 
{
    m_vacancies2 *ptr;
    void *ptr_anon;
};

/** \fn void add_vacancies2_message(int firm_id, int region_id, double firm_wage_offer_for_skill_1, double firm_wage_offer_for_skill_2, double firm_wage_offer_for_skill_3, double firm_wage_offer_for_skill_4, double firm_wage_offer_for_skill_5)
 * \brief Add vacancies2 message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param firm_wage_offer_for_skill_1 Message variable.
 * \param firm_wage_offer_for_skill_2 Message variable.
 * \param firm_wage_offer_for_skill_3 Message variable.
 * \param firm_wage_offer_for_skill_4 Message variable.
 * \param firm_wage_offer_for_skill_5 Message variable.
 */
void add_vacancies2_message(int firm_id, int region_id, double firm_wage_offer_for_skill_1, double firm_wage_offer_for_skill_2, double firm_wage_offer_for_skill_3, double firm_wage_offer_for_skill_4, double firm_wage_offer_for_skill_5)
{
    int rc;
	m_vacancies2 msg;
    
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.firm_wage_offer_for_skill_1 = firm_wage_offer_for_skill_1;
    msg.firm_wage_offer_for_skill_2 = firm_wage_offer_for_skill_2;
    msg.firm_wage_offer_for_skill_3 = firm_wage_offer_for_skill_3;
    msg.firm_wage_offer_for_skill_4 = firm_wage_offer_for_skill_4;
    msg.firm_wage_offer_for_skill_5 = firm_wage_offer_for_skill_5;
    
    
    rc = MB_AddMessage(b_vacancies2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'vacancies2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancies2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_vacancies2* getInternalMessage_vacancies2(void)
{
    static m_vacancies2 *msg_prev = NULL;
    union pu_vacancies2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_vacancies2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'vacancies2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'vacancies2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_vacancies2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'vacancies2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_vacancies2 * get_first_vacancies2_message()
 * \brief Get the first vacancies2 message in the vacancies2 message list.
 * \return The first message in the list.
 */
m_vacancies2 * get_first_vacancies2_message()
{
	return getInternalMessage_vacancies2();
}

/** \fn xmachine_message_vacancies2 * get_next_vacancies2_message(xmachine_message_vacancies2 * current)
 * \brief Get the next vacancies2 message in the vacancies2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_vacancies2 * get_next_vacancies2_message(m_vacancies2 * current)
{
	return getInternalMessage_vacancies2();
}


union pu_vacancies_r_and_d_employees 
{
    m_vacancies_r_and_d_employees *ptr;
    void *ptr_anon;
};

/** \fn void add_vacancies_r_and_d_employees_message(int firm_id, int region_id, double firm_wage_offer)
 * \brief Add vacancies_r_and_d_employees message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param firm_wage_offer Message variable.
 */
void add_vacancies_r_and_d_employees_message(int firm_id, int region_id, double firm_wage_offer)
{
    int rc;
	m_vacancies_r_and_d_employees msg;
    
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.firm_wage_offer = firm_wage_offer;
    
    
    rc = MB_AddMessage(b_vacancies_r_and_d_employees, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'vacancies_r_and_d_employees' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies_r_and_d_employees' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancies_r_and_d_employees' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_vacancies_r_and_d_employees* getInternalMessage_vacancies_r_and_d_employees(void)
{
    static m_vacancies_r_and_d_employees *msg_prev = NULL;
    union pu_vacancies_r_and_d_employees msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_vacancies_r_and_d_employees); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'vacancies_r_and_d_employees' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'vacancies_r_and_d_employees' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_vacancies_r_and_d_employees, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'vacancies_r_and_d_employees' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies_r_and_d_employees' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_vacancies_r_and_d_employees * get_first_vacancies_r_and_d_employees_message()
 * \brief Get the first vacancies_r_and_d_employees message in the vacancies_r_and_d_employees message list.
 * \return The first message in the list.
 */
m_vacancies_r_and_d_employees * get_first_vacancies_r_and_d_employees_message()
{
	return getInternalMessage_vacancies_r_and_d_employees();
}

/** \fn xmachine_message_vacancies_r_and_d_employees * get_next_vacancies_r_and_d_employees_message(xmachine_message_vacancies_r_and_d_employees * current)
 * \brief Get the next vacancies_r_and_d_employees message in the vacancies_r_and_d_employees message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_vacancies_r_and_d_employees * get_next_vacancies_r_and_d_employees_message(m_vacancies_r_and_d_employees * current)
{
	return getInternalMessage_vacancies_r_and_d_employees();
}


union pu_vacancies_r_and_d_employees2 
{
    m_vacancies_r_and_d_employees2 *ptr;
    void *ptr_anon;
};

/** \fn void add_vacancies_r_and_d_employees2_message(int firm_id, int region_id, double firm_wage_offer)
 * \brief Add vacancies_r_and_d_employees2 message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param firm_wage_offer Message variable.
 */
void add_vacancies_r_and_d_employees2_message(int firm_id, int region_id, double firm_wage_offer)
{
    int rc;
	m_vacancies_r_and_d_employees2 msg;
    
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.firm_wage_offer = firm_wage_offer;
    
    
    rc = MB_AddMessage(b_vacancies_r_and_d_employees2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'vacancies_r_and_d_employees2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies_r_and_d_employees2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancies_r_and_d_employees2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_vacancies_r_and_d_employees2* getInternalMessage_vacancies_r_and_d_employees2(void)
{
    static m_vacancies_r_and_d_employees2 *msg_prev = NULL;
    union pu_vacancies_r_and_d_employees2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_vacancies_r_and_d_employees2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'vacancies_r_and_d_employees2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'vacancies_r_and_d_employees2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_vacancies_r_and_d_employees2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'vacancies_r_and_d_employees2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies_r_and_d_employees2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_vacancies_r_and_d_employees2 * get_first_vacancies_r_and_d_employees2_message()
 * \brief Get the first vacancies_r_and_d_employees2 message in the vacancies_r_and_d_employees2 message list.
 * \return The first message in the list.
 */
m_vacancies_r_and_d_employees2 * get_first_vacancies_r_and_d_employees2_message()
{
	return getInternalMessage_vacancies_r_and_d_employees2();
}

/** \fn xmachine_message_vacancies_r_and_d_employees2 * get_next_vacancies_r_and_d_employees2_message(xmachine_message_vacancies_r_and_d_employees2 * current)
 * \brief Get the next vacancies_r_and_d_employees2 message in the vacancies_r_and_d_employees2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_vacancies_r_and_d_employees2 * get_next_vacancies_r_and_d_employees2_message(m_vacancies_r_and_d_employees2 * current)
{
	return getInternalMessage_vacancies_r_and_d_employees2();
}


union pu_firing 
{
    m_firing *ptr;
    void *ptr_anon;
};

/** \fn void add_firing_message(int firm_id, int worker_id)
 * \brief Add firing message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 */
void add_firing_message(int firm_id, int worker_id)
{
    int rc;
	m_firing msg;
    
    msg.firm_id = firm_id;
    msg.worker_id = worker_id;
    
    
    rc = MB_AddMessage(b_firing, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firing' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firing* getInternalMessage_firing(void)
{
    static m_firing *msg_prev = NULL;
    union pu_firing msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firing); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firing' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firing' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firing, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firing' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firing' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firing * get_first_firing_message()
 * \brief Get the first firing message in the firing message list.
 * \return The first message in the list.
 */
m_firing * get_first_firing_message()
{
	return getInternalMessage_firing();
}

/** \fn xmachine_message_firing * get_next_firing_message(xmachine_message_firing * current)
 * \brief Get the next firing message in the firing message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firing * get_next_firing_message(m_firing * current)
{
	return getInternalMessage_firing();
}


union pu_job_application 
{
    m_job_application *ptr;
    void *ptr_anon;
};

/** \fn void add_job_application_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, int job_type)
 * \brief Add job_application message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param specific_skill Message variable.
 * \param job_type Message variable.
 */
void add_job_application_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, int job_type)
{
    int rc;
	m_job_application msg;
    
    msg.worker_id = worker_id;
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.general_skill = general_skill;
    msg.specific_skill = specific_skill;
    msg.job_type = job_type;
    
    
    rc = MB_AddMessage(b_job_application, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_application' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_application* getInternalMessage_job_application(void)
{
    static m_job_application *msg_prev = NULL;
    union pu_job_application msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_application); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_application' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_application' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_application, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_application' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_job_application * get_first_job_application_message()
 * \brief Get the first job_application message in the job_application message list.
 * \return The first message in the list.
 */
m_job_application * get_first_job_application_message()
{
	return getInternalMessage_job_application();
}

/** \fn xmachine_message_job_application * get_next_job_application_message(xmachine_message_job_application * current)
 * \brief Get the next job_application message in the job_application message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_application * get_next_job_application_message(m_job_application * current)
{
	return getInternalMessage_job_application();
}


union pu_job_application2 
{
    m_job_application2 *ptr;
    void *ptr_anon;
};

/** \fn void add_job_application2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, int job_type)
 * \brief Add job_application2 message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param specific_skill Message variable.
 * \param job_type Message variable.
 */
void add_job_application2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, int job_type)
{
    int rc;
	m_job_application2 msg;
    
    msg.worker_id = worker_id;
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.general_skill = general_skill;
    msg.specific_skill = specific_skill;
    msg.job_type = job_type;
    
    
    rc = MB_AddMessage(b_job_application2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_application2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_application2* getInternalMessage_job_application2(void)
{
    static m_job_application2 *msg_prev = NULL;
    union pu_job_application2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_application2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_application2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_application2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_application2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_application2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_job_application2 * get_first_job_application2_message()
 * \brief Get the first job_application2 message in the job_application2 message list.
 * \return The first message in the list.
 */
m_job_application2 * get_first_job_application2_message()
{
	return getInternalMessage_job_application2();
}

/** \fn xmachine_message_job_application2 * get_next_job_application2_message(xmachine_message_job_application2 * current)
 * \brief Get the next job_application2 message in the job_application2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_application2 * get_next_job_application2_message(m_job_application2 * current)
{
	return getInternalMessage_job_application2();
}


union pu_job_offer 
{
    m_job_offer *ptr;
    void *ptr_anon;
};

/** \fn void add_job_offer_message(int firm_id, int worker_id, int region_id, double wage_offer, int job_type)
 * \brief Add job_offer message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 * \param region_id Message variable.
 * \param wage_offer Message variable.
 * \param job_type Message variable.
 */
void add_job_offer_message(int firm_id, int worker_id, int region_id, double wage_offer, int job_type)
{
    int rc;
	m_job_offer msg;
    
    msg.firm_id = firm_id;
    msg.worker_id = worker_id;
    msg.region_id = region_id;
    msg.wage_offer = wage_offer;
    msg.job_type = job_type;
    
    
    rc = MB_AddMessage(b_job_offer, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_offer' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_offer' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_offer* getInternalMessage_job_offer(void)
{
    static m_job_offer *msg_prev = NULL;
    union pu_job_offer msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_offer); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_offer' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_offer' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_offer, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_offer' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_job_offer * get_first_job_offer_message()
 * \brief Get the first job_offer message in the job_offer message list.
 * \return The first message in the list.
 */
m_job_offer * get_first_job_offer_message()
{
	return getInternalMessage_job_offer();
}

/** \fn xmachine_message_job_offer * get_next_job_offer_message(xmachine_message_job_offer * current)
 * \brief Get the next job_offer message in the job_offer message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_offer * get_next_job_offer_message(m_job_offer * current)
{
	return getInternalMessage_job_offer();
}


union pu_job_offer2 
{
    m_job_offer2 *ptr;
    void *ptr_anon;
};

/** \fn void add_job_offer2_message(int firm_id, int worker_id, int region_id, double wage_offer, int job_type)
 * \brief Add job_offer2 message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 * \param region_id Message variable.
 * \param wage_offer Message variable.
 * \param job_type Message variable.
 */
void add_job_offer2_message(int firm_id, int worker_id, int region_id, double wage_offer, int job_type)
{
    int rc;
	m_job_offer2 msg;
    
    msg.firm_id = firm_id;
    msg.worker_id = worker_id;
    msg.region_id = region_id;
    msg.wage_offer = wage_offer;
    msg.job_type = job_type;
    
    
    rc = MB_AddMessage(b_job_offer2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_offer2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_offer2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_offer2* getInternalMessage_job_offer2(void)
{
    static m_job_offer2 *msg_prev = NULL;
    union pu_job_offer2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_offer2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_offer2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_offer2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_offer2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_offer2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_job_offer2 * get_first_job_offer2_message()
 * \brief Get the first job_offer2 message in the job_offer2 message list.
 * \return The first message in the list.
 */
m_job_offer2 * get_first_job_offer2_message()
{
	return getInternalMessage_job_offer2();
}

/** \fn xmachine_message_job_offer2 * get_next_job_offer2_message(xmachine_message_job_offer2 * current)
 * \brief Get the next job_offer2 message in the job_offer2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_offer2 * get_next_job_offer2_message(m_job_offer2 * current)
{
	return getInternalMessage_job_offer2();
}


union pu_job_acceptance 
{
    m_job_acceptance *ptr;
    void *ptr_anon;
};

/** \fn void add_job_acceptance_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, int job_type)
 * \brief Add job_acceptance message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param specific_skill Message variable.
 * \param job_type Message variable.
 */
void add_job_acceptance_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, int job_type)
{
    int rc;
	m_job_acceptance msg;
    
    msg.worker_id = worker_id;
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.general_skill = general_skill;
    msg.specific_skill = specific_skill;
    msg.job_type = job_type;
    
    
    rc = MB_AddMessage(b_job_acceptance, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_acceptance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_acceptance' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_acceptance* getInternalMessage_job_acceptance(void)
{
    static m_job_acceptance *msg_prev = NULL;
    union pu_job_acceptance msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_acceptance); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_acceptance' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_acceptance' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_acceptance, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_acceptance' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_job_acceptance * get_first_job_acceptance_message()
 * \brief Get the first job_acceptance message in the job_acceptance message list.
 * \return The first message in the list.
 */
m_job_acceptance * get_first_job_acceptance_message()
{
	return getInternalMessage_job_acceptance();
}

/** \fn xmachine_message_job_acceptance * get_next_job_acceptance_message(xmachine_message_job_acceptance * current)
 * \brief Get the next job_acceptance message in the job_acceptance message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_acceptance * get_next_job_acceptance_message(m_job_acceptance * current)
{
	return getInternalMessage_job_acceptance();
}


union pu_job_acceptance2 
{
    m_job_acceptance2 *ptr;
    void *ptr_anon;
};

/** \fn void add_job_acceptance2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, int job_type)
 * \brief Add job_acceptance2 message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param specific_skill Message variable.
 * \param job_type Message variable.
 */
void add_job_acceptance2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, int job_type)
{
    int rc;
	m_job_acceptance2 msg;
    
    msg.worker_id = worker_id;
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.general_skill = general_skill;
    msg.specific_skill = specific_skill;
    msg.job_type = job_type;
    
    
    rc = MB_AddMessage(b_job_acceptance2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_acceptance2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_acceptance2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_acceptance2* getInternalMessage_job_acceptance2(void)
{
    static m_job_acceptance2 *msg_prev = NULL;
    union pu_job_acceptance2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_acceptance2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_acceptance2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_acceptance2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_acceptance2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_acceptance2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_job_acceptance2 * get_first_job_acceptance2_message()
 * \brief Get the first job_acceptance2 message in the job_acceptance2 message list.
 * \return The first message in the list.
 */
m_job_acceptance2 * get_first_job_acceptance2_message()
{
	return getInternalMessage_job_acceptance2();
}

/** \fn xmachine_message_job_acceptance2 * get_next_job_acceptance2_message(xmachine_message_job_acceptance2 * current)
 * \brief Get the next job_acceptance2 message in the job_acceptance2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_acceptance2 * get_next_job_acceptance2_message(m_job_acceptance2 * current)
{
	return getInternalMessage_job_acceptance2();
}


union pu_quitting 
{
    m_quitting *ptr;
    void *ptr_anon;
};

/** \fn void add_quitting_message(int worker_id, int firm_id)
 * \brief Add quitting message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 */
void add_quitting_message(int worker_id, int firm_id)
{
    int rc;
	m_quitting msg;
    
    msg.worker_id = worker_id;
    msg.firm_id = firm_id;
    
    
    rc = MB_AddMessage(b_quitting, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'quitting' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quitting' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_quitting* getInternalMessage_quitting(void)
{
    static m_quitting *msg_prev = NULL;
    union pu_quitting msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_quitting); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'quitting' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'quitting' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_quitting, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'quitting' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_quitting * get_first_quitting_message()
 * \brief Get the first quitting message in the quitting message list.
 * \return The first message in the list.
 */
m_quitting * get_first_quitting_message()
{
	return getInternalMessage_quitting();
}

/** \fn xmachine_message_quitting * get_next_quitting_message(xmachine_message_quitting * current)
 * \brief Get the next quitting message in the quitting message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_quitting * get_next_quitting_message(m_quitting * current)
{
	return getInternalMessage_quitting();
}


union pu_quitting2 
{
    m_quitting2 *ptr;
    void *ptr_anon;
};

/** \fn void add_quitting2_message(int worker_id, int firm_id)
 * \brief Add quitting2 message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 */
void add_quitting2_message(int worker_id, int firm_id)
{
    int rc;
	m_quitting2 msg;
    
    msg.worker_id = worker_id;
    msg.firm_id = firm_id;
    
    
    rc = MB_AddMessage(b_quitting2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'quitting2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quitting2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_quitting2* getInternalMessage_quitting2(void)
{
    static m_quitting2 *msg_prev = NULL;
    union pu_quitting2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_quitting2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'quitting2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'quitting2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_quitting2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'quitting2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_quitting2 * get_first_quitting2_message()
 * \brief Get the first quitting2 message in the quitting2 message list.
 * \return The first message in the list.
 */
m_quitting2 * get_first_quitting2_message()
{
	return getInternalMessage_quitting2();
}

/** \fn xmachine_message_quitting2 * get_next_quitting2_message(xmachine_message_quitting2 * current)
 * \brief Get the next quitting2 message in the quitting2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_quitting2 * get_next_quitting2_message(m_quitting2 * current)
{
	return getInternalMessage_quitting2();
}


union pu_unemployment_notification 
{
    m_unemployment_notification *ptr;
    void *ptr_anon;
};

/** \fn void add_unemployment_notification_message(int gov_id, double unemployment_payment)
 * \brief Add unemployment_notification message by calling internal and processing.
 * \param gov_id Message variable.
 * \param unemployment_payment Message variable.
 */
void add_unemployment_notification_message(int gov_id, double unemployment_payment)
{
    int rc;
	m_unemployment_notification msg;
    
    msg.gov_id = gov_id;
    msg.unemployment_payment = unemployment_payment;
    
    
    rc = MB_AddMessage(b_unemployment_notification, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'unemployment_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_notification' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'unemployment_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_unemployment_notification* getInternalMessage_unemployment_notification(void)
{
    static m_unemployment_notification *msg_prev = NULL;
    union pu_unemployment_notification msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_unemployment_notification); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'unemployment_notification' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'unemployment_notification' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_unemployment_notification, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'unemployment_notification' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_notification' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_unemployment_notification * get_first_unemployment_notification_message()
 * \brief Get the first unemployment_notification message in the unemployment_notification message list.
 * \return The first message in the list.
 */
m_unemployment_notification * get_first_unemployment_notification_message()
{
	return getInternalMessage_unemployment_notification();
}

/** \fn xmachine_message_unemployment_notification * get_next_unemployment_notification_message(xmachine_message_unemployment_notification * current)
 * \brief Get the next unemployment_notification message in the unemployment_notification message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_unemployment_notification * get_next_unemployment_notification_message(m_unemployment_notification * current)
{
	return getInternalMessage_unemployment_notification();
}


union pu_policy_announcement 
{
    m_policy_announcement *ptr;
    void *ptr_anon;
};

/** \fn void add_policy_announcement_message(int gov_id, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double unemployment_benefit_pct, double hh_subsidy_pct, double firm_subsidy_pct, double hh_transfer_payment, double firm_transfer_payment, double minimum_wage, double basic_security_benefits)
 * \brief Add policy_announcement message by calling internal and processing.
 * \param gov_id Message variable.
 * \param tax_rate_corporate Message variable.
 * \param tax_rate_hh_labour Message variable.
 * \param tax_rate_hh_capital Message variable.
 * \param tax_rate_vat Message variable.
 * \param unemployment_benefit_pct Message variable.
 * \param hh_subsidy_pct Message variable.
 * \param firm_subsidy_pct Message variable.
 * \param hh_transfer_payment Message variable.
 * \param firm_transfer_payment Message variable.
 * \param minimum_wage Message variable.
 * \param basic_security_benefits Message variable.
 */
void add_policy_announcement_message(int gov_id, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double unemployment_benefit_pct, double hh_subsidy_pct, double firm_subsidy_pct, double hh_transfer_payment, double firm_transfer_payment, double minimum_wage, double basic_security_benefits)
{
    int rc;
	m_policy_announcement msg;
    
    msg.gov_id = gov_id;
    msg.tax_rate_corporate = tax_rate_corporate;
    msg.tax_rate_hh_labour = tax_rate_hh_labour;
    msg.tax_rate_hh_capital = tax_rate_hh_capital;
    msg.tax_rate_vat = tax_rate_vat;
    msg.unemployment_benefit_pct = unemployment_benefit_pct;
    msg.hh_subsidy_pct = hh_subsidy_pct;
    msg.firm_subsidy_pct = firm_subsidy_pct;
    msg.hh_transfer_payment = hh_transfer_payment;
    msg.firm_transfer_payment = firm_transfer_payment;
    msg.minimum_wage = minimum_wage;
    msg.basic_security_benefits = basic_security_benefits;
    
    
    rc = MB_AddMessage(b_policy_announcement, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'policy_announcement' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'policy_announcement' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'policy_announcement' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_policy_announcement* getInternalMessage_policy_announcement(void)
{
    static m_policy_announcement *msg_prev = NULL;
    union pu_policy_announcement msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_policy_announcement); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'policy_announcement' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'policy_announcement' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_policy_announcement, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'policy_announcement' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'policy_announcement' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_policy_announcement * get_first_policy_announcement_message()
 * \brief Get the first policy_announcement message in the policy_announcement message list.
 * \return The first message in the list.
 */
m_policy_announcement * get_first_policy_announcement_message()
{
	return getInternalMessage_policy_announcement();
}

/** \fn xmachine_message_policy_announcement * get_next_policy_announcement_message(xmachine_message_policy_announcement * current)
 * \brief Get the next policy_announcement message in the policy_announcement message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_policy_announcement * get_next_policy_announcement_message(m_policy_announcement * current)
{
	return getInternalMessage_policy_announcement();
}


union pu_tax_payment 
{
    m_tax_payment *ptr;
    void *ptr_anon;
};

/** \fn void add_tax_payment_message(int gov_id, double tax_payment)
 * \brief Add tax_payment message by calling internal and processing.
 * \param gov_id Message variable.
 * \param tax_payment Message variable.
 */
void add_tax_payment_message(int gov_id, double tax_payment)
{
    int rc;
	m_tax_payment msg;
    
    msg.gov_id = gov_id;
    msg.tax_payment = tax_payment;
    
    
    rc = MB_AddMessage(b_tax_payment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'tax_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'tax_payment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'tax_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_tax_payment* getInternalMessage_tax_payment(void)
{
    static m_tax_payment *msg_prev = NULL;
    union pu_tax_payment msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_tax_payment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'tax_payment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'tax_payment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_tax_payment, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'tax_payment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'tax_payment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_tax_payment * get_first_tax_payment_message()
 * \brief Get the first tax_payment message in the tax_payment message list.
 * \return The first message in the list.
 */
m_tax_payment * get_first_tax_payment_message()
{
	return getInternalMessage_tax_payment();
}

/** \fn xmachine_message_tax_payment * get_next_tax_payment_message(xmachine_message_tax_payment * current)
 * \brief Get the next tax_payment message in the tax_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_tax_payment * get_next_tax_payment_message(m_tax_payment * current)
{
	return getInternalMessage_tax_payment();
}


union pu_unemployment_benefit_restitution 
{
    m_unemployment_benefit_restitution *ptr;
    void *ptr_anon;
};

/** \fn void add_unemployment_benefit_restitution_message(int gov_id, double restitution_payment)
 * \brief Add unemployment_benefit_restitution message by calling internal and processing.
 * \param gov_id Message variable.
 * \param restitution_payment Message variable.
 */
void add_unemployment_benefit_restitution_message(int gov_id, double restitution_payment)
{
    int rc;
	m_unemployment_benefit_restitution msg;
    
    msg.gov_id = gov_id;
    msg.restitution_payment = restitution_payment;
    
    
    rc = MB_AddMessage(b_unemployment_benefit_restitution, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'unemployment_benefit_restitution' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_benefit_restitution' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'unemployment_benefit_restitution' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_unemployment_benefit_restitution* getInternalMessage_unemployment_benefit_restitution(void)
{
    static m_unemployment_benefit_restitution *msg_prev = NULL;
    union pu_unemployment_benefit_restitution msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_unemployment_benefit_restitution); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'unemployment_benefit_restitution' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'unemployment_benefit_restitution' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_unemployment_benefit_restitution, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'unemployment_benefit_restitution' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_benefit_restitution' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_unemployment_benefit_restitution * get_first_unemployment_benefit_restitution_message()
 * \brief Get the first unemployment_benefit_restitution message in the unemployment_benefit_restitution message list.
 * \return The first message in the list.
 */
m_unemployment_benefit_restitution * get_first_unemployment_benefit_restitution_message()
{
	return getInternalMessage_unemployment_benefit_restitution();
}

/** \fn xmachine_message_unemployment_benefit_restitution * get_next_unemployment_benefit_restitution_message(xmachine_message_unemployment_benefit_restitution * current)
 * \brief Get the next unemployment_benefit_restitution message in the unemployment_benefit_restitution message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_unemployment_benefit_restitution * get_next_unemployment_benefit_restitution_message(m_unemployment_benefit_restitution * current)
{
	return getInternalMessage_unemployment_benefit_restitution();
}


union pu_hh_transfer_notification 
{
    m_hh_transfer_notification *ptr;
    void *ptr_anon;
};

/** \fn void add_hh_transfer_notification_message(int gov_id)
 * \brief Add hh_transfer_notification message by calling internal and processing.
 * \param gov_id Message variable.
 */
void add_hh_transfer_notification_message(int gov_id)
{
    int rc;
	m_hh_transfer_notification msg;
    
    msg.gov_id = gov_id;
    
    
    rc = MB_AddMessage(b_hh_transfer_notification, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'hh_transfer_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_hh_transfer_notification* getInternalMessage_hh_transfer_notification(void)
{
    static m_hh_transfer_notification *msg_prev = NULL;
    union pu_hh_transfer_notification msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_hh_transfer_notification); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'hh_transfer_notification' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'hh_transfer_notification' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_hh_transfer_notification, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'hh_transfer_notification' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_hh_transfer_notification * get_first_hh_transfer_notification_message()
 * \brief Get the first hh_transfer_notification message in the hh_transfer_notification message list.
 * \return The first message in the list.
 */
m_hh_transfer_notification * get_first_hh_transfer_notification_message()
{
	return getInternalMessage_hh_transfer_notification();
}

/** \fn xmachine_message_hh_transfer_notification * get_next_hh_transfer_notification_message(xmachine_message_hh_transfer_notification * current)
 * \brief Get the next hh_transfer_notification message in the hh_transfer_notification message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_hh_transfer_notification * get_next_hh_transfer_notification_message(m_hh_transfer_notification * current)
{
	return getInternalMessage_hh_transfer_notification();
}


union pu_hh_subsidy_notification 
{
    m_hh_subsidy_notification *ptr;
    void *ptr_anon;
};

/** \fn void add_hh_subsidy_notification_message(int gov_id, double subsidy_payment)
 * \brief Add hh_subsidy_notification message by calling internal and processing.
 * \param gov_id Message variable.
 * \param subsidy_payment Message variable.
 */
void add_hh_subsidy_notification_message(int gov_id, double subsidy_payment)
{
    int rc;
	m_hh_subsidy_notification msg;
    
    msg.gov_id = gov_id;
    msg.subsidy_payment = subsidy_payment;
    
    
    rc = MB_AddMessage(b_hh_subsidy_notification, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'hh_subsidy_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_hh_subsidy_notification* getInternalMessage_hh_subsidy_notification(void)
{
    static m_hh_subsidy_notification *msg_prev = NULL;
    union pu_hh_subsidy_notification msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_hh_subsidy_notification); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'hh_subsidy_notification' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'hh_subsidy_notification' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_hh_subsidy_notification, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'hh_subsidy_notification' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_hh_subsidy_notification * get_first_hh_subsidy_notification_message()
 * \brief Get the first hh_subsidy_notification message in the hh_subsidy_notification message list.
 * \return The first message in the list.
 */
m_hh_subsidy_notification * get_first_hh_subsidy_notification_message()
{
	return getInternalMessage_hh_subsidy_notification();
}

/** \fn xmachine_message_hh_subsidy_notification * get_next_hh_subsidy_notification_message(xmachine_message_hh_subsidy_notification * current)
 * \brief Get the next hh_subsidy_notification message in the hh_subsidy_notification message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_hh_subsidy_notification * get_next_hh_subsidy_notification_message(m_hh_subsidy_notification * current)
{
	return getInternalMessage_hh_subsidy_notification();
}


union pu_human_capital_policy_announcement 
{
    m_human_capital_policy_announcement *ptr;
    void *ptr_anon;
};

/** \fn void add_human_capital_policy_announcement_message(int gov_id, int announcement)
 * \brief Add human_capital_policy_announcement message by calling internal and processing.
 * \param gov_id Message variable.
 * \param announcement Message variable.
 */
void add_human_capital_policy_announcement_message(int gov_id, int announcement)
{
    int rc;
	m_human_capital_policy_announcement msg;
    
    msg.gov_id = gov_id;
    msg.announcement = announcement;
    
    
    rc = MB_AddMessage(b_human_capital_policy_announcement, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'human_capital_policy_announcement' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'human_capital_policy_announcement' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'human_capital_policy_announcement' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_human_capital_policy_announcement* getInternalMessage_human_capital_policy_announcement(void)
{
    static m_human_capital_policy_announcement *msg_prev = NULL;
    union pu_human_capital_policy_announcement msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_human_capital_policy_announcement); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'human_capital_policy_announcement' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'human_capital_policy_announcement' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_human_capital_policy_announcement, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'human_capital_policy_announcement' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'human_capital_policy_announcement' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_human_capital_policy_announcement * get_first_human_capital_policy_announcement_message()
 * \brief Get the first human_capital_policy_announcement message in the human_capital_policy_announcement message list.
 * \return The first message in the list.
 */
m_human_capital_policy_announcement * get_first_human_capital_policy_announcement_message()
{
	return getInternalMessage_human_capital_policy_announcement();
}

/** \fn xmachine_message_human_capital_policy_announcement * get_next_human_capital_policy_announcement_message(xmachine_message_human_capital_policy_announcement * current)
 * \brief Get the next human_capital_policy_announcement message in the human_capital_policy_announcement message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_human_capital_policy_announcement * get_next_human_capital_policy_announcement_message(m_human_capital_policy_announcement * current)
{
	return getInternalMessage_human_capital_policy_announcement();
}


union pu_firm_transfer_notification 
{
    m_firm_transfer_notification *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_transfer_notification_message(int gov_id)
 * \brief Add firm_transfer_notification message by calling internal and processing.
 * \param gov_id Message variable.
 */
void add_firm_transfer_notification_message(int gov_id)
{
    int rc;
	m_firm_transfer_notification msg;
    
    msg.gov_id = gov_id;
    
    
    rc = MB_AddMessage(b_firm_transfer_notification, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_transfer_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_transfer_notification* getInternalMessage_firm_transfer_notification(void)
{
    static m_firm_transfer_notification *msg_prev = NULL;
    union pu_firm_transfer_notification msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_transfer_notification); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_transfer_notification' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_transfer_notification' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_transfer_notification, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_transfer_notification' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_transfer_notification * get_first_firm_transfer_notification_message()
 * \brief Get the first firm_transfer_notification message in the firm_transfer_notification message list.
 * \return The first message in the list.
 */
m_firm_transfer_notification * get_first_firm_transfer_notification_message()
{
	return getInternalMessage_firm_transfer_notification();
}

/** \fn xmachine_message_firm_transfer_notification * get_next_firm_transfer_notification_message(xmachine_message_firm_transfer_notification * current)
 * \brief Get the next firm_transfer_notification message in the firm_transfer_notification message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_transfer_notification * get_next_firm_transfer_notification_message(m_firm_transfer_notification * current)
{
	return getInternalMessage_firm_transfer_notification();
}


union pu_firm_subsidy_notification 
{
    m_firm_subsidy_notification *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_subsidy_notification_message(int gov_id, double subsidy_payment)
 * \brief Add firm_subsidy_notification message by calling internal and processing.
 * \param gov_id Message variable.
 * \param subsidy_payment Message variable.
 */
void add_firm_subsidy_notification_message(int gov_id, double subsidy_payment)
{
    int rc;
	m_firm_subsidy_notification msg;
    
    msg.gov_id = gov_id;
    msg.subsidy_payment = subsidy_payment;
    
    
    rc = MB_AddMessage(b_firm_subsidy_notification, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_subsidy_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_subsidy_notification* getInternalMessage_firm_subsidy_notification(void)
{
    static m_firm_subsidy_notification *msg_prev = NULL;
    union pu_firm_subsidy_notification msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_subsidy_notification); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_subsidy_notification' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_subsidy_notification' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_subsidy_notification, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_subsidy_notification' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_subsidy_notification * get_first_firm_subsidy_notification_message()
 * \brief Get the first firm_subsidy_notification message in the firm_subsidy_notification message list.
 * \return The first message in the list.
 */
m_firm_subsidy_notification * get_first_firm_subsidy_notification_message()
{
	return getInternalMessage_firm_subsidy_notification();
}

/** \fn xmachine_message_firm_subsidy_notification * get_next_firm_subsidy_notification_message(xmachine_message_firm_subsidy_notification * current)
 * \brief Get the next firm_subsidy_notification message in the firm_subsidy_notification message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_subsidy_notification * get_next_firm_subsidy_notification_message(m_firm_subsidy_notification * current)
{
	return getInternalMessage_firm_subsidy_notification();
}


union pu_request_fiat_money 
{
    m_request_fiat_money *ptr;
    void *ptr_anon;
};

/** \fn void add_request_fiat_money_message(double nominal_value)
 * \brief Add request_fiat_money message by calling internal and processing.
 * \param nominal_value Message variable.
 */
void add_request_fiat_money_message(double nominal_value)
{
    int rc;
	m_request_fiat_money msg;
    
    msg.nominal_value = nominal_value;
    
    
    rc = MB_AddMessage(b_request_fiat_money, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'request_fiat_money' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'request_fiat_money' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'request_fiat_money' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_request_fiat_money* getInternalMessage_request_fiat_money(void)
{
    static m_request_fiat_money *msg_prev = NULL;
    union pu_request_fiat_money msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_request_fiat_money); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'request_fiat_money' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'request_fiat_money' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_request_fiat_money, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'request_fiat_money' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'request_fiat_money' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_request_fiat_money * get_first_request_fiat_money_message()
 * \brief Get the first request_fiat_money message in the request_fiat_money message list.
 * \return The first message in the list.
 */
m_request_fiat_money * get_first_request_fiat_money_message()
{
	return getInternalMessage_request_fiat_money();
}

/** \fn xmachine_message_request_fiat_money * get_next_request_fiat_money_message(xmachine_message_request_fiat_money * current)
 * \brief Get the next request_fiat_money message in the request_fiat_money message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_request_fiat_money * get_next_request_fiat_money_message(m_request_fiat_money * current)
{
	return getInternalMessage_request_fiat_money();
}


union pu_human_capital_policy_general_skill_information 
{
    m_human_capital_policy_general_skill_information *ptr;
    void *ptr_anon;
};

/** \fn void add_human_capital_policy_general_skill_information_message(int id, int gov_id, int general_skills)
 * \brief Add human_capital_policy_general_skill_information message by calling internal and processing.
 * \param id Message variable.
 * \param gov_id Message variable.
 * \param general_skills Message variable.
 */
void add_human_capital_policy_general_skill_information_message(int id, int gov_id, int general_skills)
{
    int rc;
	m_human_capital_policy_general_skill_information msg;
    
    msg.id = id;
    msg.gov_id = gov_id;
    msg.general_skills = general_skills;
    
    
    rc = MB_AddMessage(b_human_capital_policy_general_skill_information, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'human_capital_policy_general_skill_information' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'human_capital_policy_general_skill_information' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'human_capital_policy_general_skill_information' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_human_capital_policy_general_skill_information* getInternalMessage_human_capital_policy_general_skill_information(void)
{
    static m_human_capital_policy_general_skill_information *msg_prev = NULL;
    union pu_human_capital_policy_general_skill_information msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_human_capital_policy_general_skill_information); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'human_capital_policy_general_skill_information' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'human_capital_policy_general_skill_information' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_human_capital_policy_general_skill_information, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'human_capital_policy_general_skill_information' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'human_capital_policy_general_skill_information' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_human_capital_policy_general_skill_information * get_first_human_capital_policy_general_skill_information_message()
 * \brief Get the first human_capital_policy_general_skill_information message in the human_capital_policy_general_skill_information message list.
 * \return The first message in the list.
 */
m_human_capital_policy_general_skill_information * get_first_human_capital_policy_general_skill_information_message()
{
	return getInternalMessage_human_capital_policy_general_skill_information();
}

/** \fn xmachine_message_human_capital_policy_general_skill_information * get_next_human_capital_policy_general_skill_information_message(xmachine_message_human_capital_policy_general_skill_information * current)
 * \brief Get the next human_capital_policy_general_skill_information message in the human_capital_policy_general_skill_information message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_human_capital_policy_general_skill_information * get_next_human_capital_policy_general_skill_information_message(m_human_capital_policy_general_skill_information * current)
{
	return getInternalMessage_human_capital_policy_general_skill_information();
}


union pu_human_capital_policy_new_general_skill_notification 
{
    m_human_capital_policy_new_general_skill_notification *ptr;
    void *ptr_anon;
};

/** \fn void add_human_capital_policy_new_general_skill_notification_message(int id, int gov_id, int general_skills)
 * \brief Add human_capital_policy_new_general_skill_notification message by calling internal and processing.
 * \param id Message variable.
 * \param gov_id Message variable.
 * \param general_skills Message variable.
 */
void add_human_capital_policy_new_general_skill_notification_message(int id, int gov_id, int general_skills)
{
    int rc;
	m_human_capital_policy_new_general_skill_notification msg;
    
    msg.id = id;
    msg.gov_id = gov_id;
    msg.general_skills = general_skills;
    
    
    rc = MB_AddMessage(b_human_capital_policy_new_general_skill_notification, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'human_capital_policy_new_general_skill_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'human_capital_policy_new_general_skill_notification' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'human_capital_policy_new_general_skill_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_human_capital_policy_new_general_skill_notification* getInternalMessage_human_capital_policy_new_general_skill_notification(void)
{
    static m_human_capital_policy_new_general_skill_notification *msg_prev = NULL;
    union pu_human_capital_policy_new_general_skill_notification msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_human_capital_policy_new_general_skill_notification); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'human_capital_policy_new_general_skill_notification' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'human_capital_policy_new_general_skill_notification' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_human_capital_policy_new_general_skill_notification, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'human_capital_policy_new_general_skill_notification' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'human_capital_policy_new_general_skill_notification' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_human_capital_policy_new_general_skill_notification * get_first_human_capital_policy_new_general_skill_notification_message()
 * \brief Get the first human_capital_policy_new_general_skill_notification message in the human_capital_policy_new_general_skill_notification message list.
 * \return The first message in the list.
 */
m_human_capital_policy_new_general_skill_notification * get_first_human_capital_policy_new_general_skill_notification_message()
{
	return getInternalMessage_human_capital_policy_new_general_skill_notification();
}

/** \fn xmachine_message_human_capital_policy_new_general_skill_notification * get_next_human_capital_policy_new_general_skill_notification_message(xmachine_message_human_capital_policy_new_general_skill_notification * current)
 * \brief Get the next human_capital_policy_new_general_skill_notification message in the human_capital_policy_new_general_skill_notification message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_human_capital_policy_new_general_skill_notification * get_next_human_capital_policy_new_general_skill_notification_message(m_human_capital_policy_new_general_skill_notification * current)
{
	return getInternalMessage_human_capital_policy_new_general_skill_notification();
}


union pu_firm_send_data 
{
    m_firm_send_data *ptr;
    void *ptr_anon;
};

/** \fn void add_firm_send_data_message(int firm_id, int region_id, int vacancies, int posted_vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, int employees_production, int employees_r_and_d, double average_wage, double average_wage_production, double average_wage_r_and_d, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double cum_revenue, double capital_costs, double net_earnings, double total_debt, double total_assets, double equity, double price, double price_last_month, double quality, double total_supply, double cum_total_sold_quantity, double output, double planned_output, int age, double firm_productivity, double firm_productivity_progress, double value_inventory, double units_capital_stock, double base_wage_offer, double dividends, double used_capital, double technology, double mark_up, int zero_output_for_longer, double unit_labor_costs)
 * \brief Add firm_send_data message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param vacancies Message variable.
 * \param posted_vacancies Message variable.
 * \param employees Message variable.
 * \param employees_skill_1 Message variable.
 * \param employees_skill_2 Message variable.
 * \param employees_skill_3 Message variable.
 * \param employees_skill_4 Message variable.
 * \param employees_skill_5 Message variable.
 * \param employees_production Message variable.
 * \param employees_r_and_d Message variable.
 * \param average_wage Message variable.
 * \param average_wage_production Message variable.
 * \param average_wage_r_and_d Message variable.
 * \param average_s_skill Message variable.
 * \param average_s_skill_1 Message variable.
 * \param average_s_skill_2 Message variable.
 * \param average_s_skill_3 Message variable.
 * \param average_s_skill_4 Message variable.
 * \param average_s_skill_5 Message variable.
 * \param cum_revenue Message variable.
 * \param capital_costs Message variable.
 * \param net_earnings Message variable.
 * \param total_debt Message variable.
 * \param total_assets Message variable.
 * \param equity Message variable.
 * \param price Message variable.
 * \param price_last_month Message variable.
 * \param quality Message variable.
 * \param total_supply Message variable.
 * \param cum_total_sold_quantity Message variable.
 * \param output Message variable.
 * \param planned_output Message variable.
 * \param age Message variable.
 * \param firm_productivity Message variable.
 * \param firm_productivity_progress Message variable.
 * \param value_inventory Message variable.
 * \param units_capital_stock Message variable.
 * \param base_wage_offer Message variable.
 * \param dividends Message variable.
 * \param used_capital Message variable.
 * \param technology Message variable.
 * \param mark_up Message variable.
 * \param zero_output_for_longer Message variable.
 * \param unit_labor_costs Message variable.
 */
void add_firm_send_data_message(int firm_id, int region_id, int vacancies, int posted_vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, int employees_production, int employees_r_and_d, double average_wage, double average_wage_production, double average_wage_r_and_d, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double cum_revenue, double capital_costs, double net_earnings, double total_debt, double total_assets, double equity, double price, double price_last_month, double quality, double total_supply, double cum_total_sold_quantity, double output, double planned_output, int age, double firm_productivity, double firm_productivity_progress, double value_inventory, double units_capital_stock, double base_wage_offer, double dividends, double used_capital, double technology, double mark_up, int zero_output_for_longer, double unit_labor_costs)
{
    int rc;
	m_firm_send_data msg;
    
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.vacancies = vacancies;
    msg.posted_vacancies = posted_vacancies;
    msg.employees = employees;
    msg.employees_skill_1 = employees_skill_1;
    msg.employees_skill_2 = employees_skill_2;
    msg.employees_skill_3 = employees_skill_3;
    msg.employees_skill_4 = employees_skill_4;
    msg.employees_skill_5 = employees_skill_5;
    msg.employees_production = employees_production;
    msg.employees_r_and_d = employees_r_and_d;
    msg.average_wage = average_wage;
    msg.average_wage_production = average_wage_production;
    msg.average_wage_r_and_d = average_wage_r_and_d;
    msg.average_s_skill = average_s_skill;
    msg.average_s_skill_1 = average_s_skill_1;
    msg.average_s_skill_2 = average_s_skill_2;
    msg.average_s_skill_3 = average_s_skill_3;
    msg.average_s_skill_4 = average_s_skill_4;
    msg.average_s_skill_5 = average_s_skill_5;
    msg.cum_revenue = cum_revenue;
    msg.capital_costs = capital_costs;
    msg.net_earnings = net_earnings;
    msg.total_debt = total_debt;
    msg.total_assets = total_assets;
    msg.equity = equity;
    msg.price = price;
    msg.price_last_month = price_last_month;
    msg.quality = quality;
    msg.total_supply = total_supply;
    msg.cum_total_sold_quantity = cum_total_sold_quantity;
    msg.output = output;
    msg.planned_output = planned_output;
    msg.age = age;
    msg.firm_productivity = firm_productivity;
    msg.firm_productivity_progress = firm_productivity_progress;
    msg.value_inventory = value_inventory;
    msg.units_capital_stock = units_capital_stock;
    msg.base_wage_offer = base_wage_offer;
    msg.dividends = dividends;
    msg.used_capital = used_capital;
    msg.technology = technology;
    msg.mark_up = mark_up;
    msg.zero_output_for_longer = zero_output_for_longer;
    msg.unit_labor_costs = unit_labor_costs;
    
    
    rc = MB_AddMessage(b_firm_send_data, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_send_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_send_data' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_send_data' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_send_data* getInternalMessage_firm_send_data(void)
{
    static m_firm_send_data *msg_prev = NULL;
    union pu_firm_send_data msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_send_data); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_send_data' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_send_data' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_send_data, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_send_data' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_send_data' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_firm_send_data * get_first_firm_send_data_message()
 * \brief Get the first firm_send_data message in the firm_send_data message list.
 * \return The first message in the list.
 */
m_firm_send_data * get_first_firm_send_data_message()
{
	return getInternalMessage_firm_send_data();
}

/** \fn xmachine_message_firm_send_data * get_next_firm_send_data_message(xmachine_message_firm_send_data * current)
 * \brief Get the next firm_send_data message in the firm_send_data message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_send_data * get_next_firm_send_data_message(m_firm_send_data * current)
{
	return getInternalMessage_firm_send_data();
}


union pu_government_send_data 
{
    m_government_send_data *ptr;
    void *ptr_anon;
};

/** \fn void add_government_send_data_message(int gov_id, int region_id, double consumption_expenditures)
 * \brief Add government_send_data message by calling internal and processing.
 * \param gov_id Message variable.
 * \param region_id Message variable.
 * \param consumption_expenditures Message variable.
 */
void add_government_send_data_message(int gov_id, int region_id, double consumption_expenditures)
{
    int rc;
	m_government_send_data msg;
    
    msg.gov_id = gov_id;
    msg.region_id = region_id;
    msg.consumption_expenditures = consumption_expenditures;
    
    
    rc = MB_AddMessage(b_government_send_data, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'government_send_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'government_send_data' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'government_send_data' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_government_send_data* getInternalMessage_government_send_data(void)
{
    static m_government_send_data *msg_prev = NULL;
    union pu_government_send_data msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_government_send_data); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'government_send_data' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'government_send_data' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_government_send_data, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'government_send_data' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'government_send_data' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_government_send_data * get_first_government_send_data_message()
 * \brief Get the first government_send_data message in the government_send_data message list.
 * \return The first message in the list.
 */
m_government_send_data * get_first_government_send_data_message()
{
	return getInternalMessage_government_send_data();
}

/** \fn xmachine_message_government_send_data * get_next_government_send_data_message(xmachine_message_government_send_data * current)
 * \brief Get the next government_send_data message in the government_send_data message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_government_send_data * get_next_government_send_data_message(m_government_send_data * current)
{
	return getInternalMessage_government_send_data();
}


union pu_household_send_data 
{
    m_household_send_data *ptr;
    void *ptr_anon;
};

/** \fn void add_household_send_data_message(int household_id, int region_id, int general_skill, int employment_status, double wage, double specific_skill, int just_employed, int just_unemployed, int start_employed, int start_unemployed, int enter_matching, int unemployed_duration, double consumption_budget_in_month, double payment_account, double mean_net_income, double wealth, double dividends, double interest_income, double net_inflows_financial_market, double reservation_wage)
 * \brief Add household_send_data message by calling internal and processing.
 * \param household_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param employment_status Message variable.
 * \param wage Message variable.
 * \param specific_skill Message variable.
 * \param just_employed Message variable.
 * \param just_unemployed Message variable.
 * \param start_employed Message variable.
 * \param start_unemployed Message variable.
 * \param enter_matching Message variable.
 * \param unemployed_duration Message variable.
 * \param consumption_budget_in_month Message variable.
 * \param payment_account Message variable.
 * \param mean_net_income Message variable.
 * \param wealth Message variable.
 * \param dividends Message variable.
 * \param interest_income Message variable.
 * \param net_inflows_financial_market Message variable.
 * \param reservation_wage Message variable.
 */
void add_household_send_data_message(int household_id, int region_id, int general_skill, int employment_status, double wage, double specific_skill, int just_employed, int just_unemployed, int start_employed, int start_unemployed, int enter_matching, int unemployed_duration, double consumption_budget_in_month, double payment_account, double mean_net_income, double wealth, double dividends, double interest_income, double net_inflows_financial_market, double reservation_wage)
{
    int rc;
	m_household_send_data msg;
    
    msg.household_id = household_id;
    msg.region_id = region_id;
    msg.general_skill = general_skill;
    msg.employment_status = employment_status;
    msg.wage = wage;
    msg.specific_skill = specific_skill;
    msg.just_employed = just_employed;
    msg.just_unemployed = just_unemployed;
    msg.start_employed = start_employed;
    msg.start_unemployed = start_unemployed;
    msg.enter_matching = enter_matching;
    msg.unemployed_duration = unemployed_duration;
    msg.consumption_budget_in_month = consumption_budget_in_month;
    msg.payment_account = payment_account;
    msg.mean_net_income = mean_net_income;
    msg.wealth = wealth;
    msg.dividends = dividends;
    msg.interest_income = interest_income;
    msg.net_inflows_financial_market = net_inflows_financial_market;
    msg.reservation_wage = reservation_wage;
    
    
    rc = MB_AddMessage(b_household_send_data, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'household_send_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_send_data' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_send_data' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_household_send_data* getInternalMessage_household_send_data(void)
{
    static m_household_send_data *msg_prev = NULL;
    union pu_household_send_data msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_household_send_data); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'household_send_data' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'household_send_data' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_household_send_data, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'household_send_data' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_send_data' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_household_send_data * get_first_household_send_data_message()
 * \brief Get the first household_send_data message in the household_send_data message list.
 * \return The first message in the list.
 */
m_household_send_data * get_first_household_send_data_message()
{
	return getInternalMessage_household_send_data();
}

/** \fn xmachine_message_household_send_data * get_next_household_send_data_message(xmachine_message_household_send_data * current)
 * \brief Get the next household_send_data message in the household_send_data message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_household_send_data * get_next_household_send_data_message(m_household_send_data * current)
{
	return getInternalMessage_household_send_data();
}


union pu_mall_data 
{
    m_mall_data *ptr;
    void *ptr_anon;
};

/** \fn void add_mall_data_message(int mall_id, int firm_region, int household_region, double export_volume, double export_value, double export_previous_value)
 * \brief Add mall_data message by calling internal and processing.
 * \param mall_id Message variable.
 * \param firm_region Message variable.
 * \param household_region Message variable.
 * \param export_volume Message variable.
 * \param export_value Message variable.
 * \param export_previous_value Message variable.
 */
void add_mall_data_message(int mall_id, int firm_region, int household_region, double export_volume, double export_value, double export_previous_value)
{
    int rc;
	m_mall_data msg;
    
    msg.mall_id = mall_id;
    msg.firm_region = firm_region;
    msg.household_region = household_region;
    msg.export_volume = export_volume;
    msg.export_value = export_value;
    msg.export_previous_value = export_previous_value;
    
    
    rc = MB_AddMessage(b_mall_data, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'mall_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mall_data' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mall_data' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_mall_data* getInternalMessage_mall_data(void)
{
    static m_mall_data *msg_prev = NULL;
    union pu_mall_data msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_mall_data); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'mall_data' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'mall_data' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_mall_data, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'mall_data' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mall_data' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_mall_data * get_first_mall_data_message()
 * \brief Get the first mall_data message in the mall_data message list.
 * \return The first message in the list.
 */
m_mall_data * get_first_mall_data_message()
{
	return getInternalMessage_mall_data();
}

/** \fn xmachine_message_mall_data * get_next_mall_data_message(xmachine_message_mall_data * current)
 * \brief Get the next mall_data message in the mall_data message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_mall_data * get_next_mall_data_message(m_mall_data * current)
{
	return getInternalMessage_mall_data();
}


union pu_eurostat_send_specific_skills 
{
    m_eurostat_send_specific_skills *ptr;
    void *ptr_anon;
};

/** \fn void add_eurostat_send_specific_skills_message(int region_id, double specific_skill, double specific_skill_1, double specific_skill_2, double specific_skill_3, double specific_skill_4, double specific_skill_5, double productivity_progress, double average_wage, double vacancy_filling_rate, double average_output, double cpi, double price_index, int no_firms, double average_quality, double average_price, double wage_offer, double technology)
 * \brief Add eurostat_send_specific_skills message by calling internal and processing.
 * \param region_id Message variable.
 * \param specific_skill Message variable.
 * \param specific_skill_1 Message variable.
 * \param specific_skill_2 Message variable.
 * \param specific_skill_3 Message variable.
 * \param specific_skill_4 Message variable.
 * \param specific_skill_5 Message variable.
 * \param productivity_progress Message variable.
 * \param average_wage Message variable.
 * \param vacancy_filling_rate Message variable.
 * \param average_output Message variable.
 * \param cpi Message variable.
 * \param price_index Message variable.
 * \param no_firms Message variable.
 * \param average_quality Message variable.
 * \param average_price Message variable.
 * \param wage_offer Message variable.
 * \param technology Message variable.
 */
void add_eurostat_send_specific_skills_message(int region_id, double specific_skill, double specific_skill_1, double specific_skill_2, double specific_skill_3, double specific_skill_4, double specific_skill_5, double productivity_progress, double average_wage, double vacancy_filling_rate, double average_output, double cpi, double price_index, int no_firms, double average_quality, double average_price, double wage_offer, double technology)
{
    int rc;
	m_eurostat_send_specific_skills msg;
    
    msg.region_id = region_id;
    msg.specific_skill = specific_skill;
    msg.specific_skill_1 = specific_skill_1;
    msg.specific_skill_2 = specific_skill_2;
    msg.specific_skill_3 = specific_skill_3;
    msg.specific_skill_4 = specific_skill_4;
    msg.specific_skill_5 = specific_skill_5;
    msg.productivity_progress = productivity_progress;
    msg.average_wage = average_wage;
    msg.vacancy_filling_rate = vacancy_filling_rate;
    msg.average_output = average_output;
    msg.cpi = cpi;
    msg.price_index = price_index;
    msg.no_firms = no_firms;
    msg.average_quality = average_quality;
    msg.average_price = average_price;
    msg.wage_offer = wage_offer;
    msg.technology = technology;
    
    
    rc = MB_AddMessage(b_eurostat_send_specific_skills, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'eurostat_send_specific_skills' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_eurostat_send_specific_skills* getInternalMessage_eurostat_send_specific_skills(void)
{
    static m_eurostat_send_specific_skills *msg_prev = NULL;
    union pu_eurostat_send_specific_skills msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_eurostat_send_specific_skills); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'eurostat_send_specific_skills' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_eurostat_send_specific_skills, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'eurostat_send_specific_skills' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_eurostat_send_specific_skills * get_first_eurostat_send_specific_skills_message()
 * \brief Get the first eurostat_send_specific_skills message in the eurostat_send_specific_skills message list.
 * \return The first message in the list.
 */
m_eurostat_send_specific_skills * get_first_eurostat_send_specific_skills_message()
{
	return getInternalMessage_eurostat_send_specific_skills();
}

/** \fn xmachine_message_eurostat_send_specific_skills * get_next_eurostat_send_specific_skills_message(xmachine_message_eurostat_send_specific_skills * current)
 * \brief Get the next eurostat_send_specific_skills message in the eurostat_send_specific_skills message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_eurostat_send_specific_skills * get_next_eurostat_send_specific_skills_message(m_eurostat_send_specific_skills * current)
{
	return getInternalMessage_eurostat_send_specific_skills();
}


union pu_data_for_government 
{
    m_data_for_government *ptr;
    void *ptr_anon;
};

/** \fn void add_data_for_government_message(int region_id, double gdp, double mean_wage, double unemployment_rate, double consumption_quota, double consumption_budget_per_capita)
 * \brief Add data_for_government message by calling internal and processing.
 * \param region_id Message variable.
 * \param gdp Message variable.
 * \param mean_wage Message variable.
 * \param unemployment_rate Message variable.
 * \param consumption_quota Message variable.
 * \param consumption_budget_per_capita Message variable.
 */
void add_data_for_government_message(int region_id, double gdp, double mean_wage, double unemployment_rate, double consumption_quota, double consumption_budget_per_capita)
{
    int rc;
	m_data_for_government msg;
    
    msg.region_id = region_id;
    msg.gdp = gdp;
    msg.mean_wage = mean_wage;
    msg.unemployment_rate = unemployment_rate;
    msg.consumption_quota = consumption_quota;
    msg.consumption_budget_per_capita = consumption_budget_per_capita;
    
    
    rc = MB_AddMessage(b_data_for_government, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'data_for_government' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'data_for_government' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'data_for_government' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_data_for_government* getInternalMessage_data_for_government(void)
{
    static m_data_for_government *msg_prev = NULL;
    union pu_data_for_government msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_data_for_government); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'data_for_government' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'data_for_government' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_data_for_government, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'data_for_government' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'data_for_government' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_data_for_government * get_first_data_for_government_message()
 * \brief Get the first data_for_government message in the data_for_government message list.
 * \return The first message in the list.
 */
m_data_for_government * get_first_data_for_government_message()
{
	return getInternalMessage_data_for_government();
}

/** \fn xmachine_message_data_for_government * get_next_data_for_government_message(xmachine_message_data_for_government * current)
 * \brief Get the next data_for_government message in the data_for_government message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_data_for_government * get_next_data_for_government_message(m_data_for_government * current)
{
	return getInternalMessage_data_for_government();
}


union pu_eurostat_send_macrodata 
{
    m_eurostat_send_macrodata *ptr;
    void *ptr_anon;
};

/** \fn void add_eurostat_send_macrodata_message(double inflation, double gdp, double unemployment_rate)
 * \brief Add eurostat_send_macrodata message by calling internal and processing.
 * \param inflation Message variable.
 * \param gdp Message variable.
 * \param unemployment_rate Message variable.
 */
void add_eurostat_send_macrodata_message(double inflation, double gdp, double unemployment_rate)
{
    int rc;
	m_eurostat_send_macrodata msg;
    
    msg.inflation = inflation;
    msg.gdp = gdp;
    msg.unemployment_rate = unemployment_rate;
    
    
    rc = MB_AddMessage(b_eurostat_send_macrodata, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'eurostat_send_macrodata' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'eurostat_send_macrodata' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'eurostat_send_macrodata' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_eurostat_send_macrodata* getInternalMessage_eurostat_send_macrodata(void)
{
    static m_eurostat_send_macrodata *msg_prev = NULL;
    union pu_eurostat_send_macrodata msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_eurostat_send_macrodata); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'eurostat_send_macrodata' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'eurostat_send_macrodata' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_eurostat_send_macrodata, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'eurostat_send_macrodata' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'eurostat_send_macrodata' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_eurostat_send_macrodata * get_first_eurostat_send_macrodata_message()
 * \brief Get the first eurostat_send_macrodata message in the eurostat_send_macrodata message list.
 * \return The first message in the list.
 */
m_eurostat_send_macrodata * get_first_eurostat_send_macrodata_message()
{
	return getInternalMessage_eurostat_send_macrodata();
}

/** \fn xmachine_message_eurostat_send_macrodata * get_next_eurostat_send_macrodata_message(xmachine_message_eurostat_send_macrodata * current)
 * \brief Get the next eurostat_send_macrodata message in the eurostat_send_macrodata message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_eurostat_send_macrodata * get_next_eurostat_send_macrodata_message(m_eurostat_send_macrodata * current)
{
	return getInternalMessage_eurostat_send_macrodata();
}


union pu_msg_firm_id_to_malls 
{
    m_msg_firm_id_to_malls *ptr;
    void *ptr_anon;
};

/** \fn void add_msg_firm_id_to_malls_message(int firm_id, int region_id)
 * \brief Add msg_firm_id_to_malls message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 */
void add_msg_firm_id_to_malls_message(int firm_id, int region_id)
{
    int rc;
	m_msg_firm_id_to_malls msg;
    
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    
    
    rc = MB_AddMessage(b_msg_firm_id_to_malls, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'msg_firm_id_to_malls' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'msg_firm_id_to_malls' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'msg_firm_id_to_malls' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_msg_firm_id_to_malls* getInternalMessage_msg_firm_id_to_malls(void)
{
    static m_msg_firm_id_to_malls *msg_prev = NULL;
    union pu_msg_firm_id_to_malls msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_msg_firm_id_to_malls); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'msg_firm_id_to_malls' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'msg_firm_id_to_malls' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_msg_firm_id_to_malls, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'msg_firm_id_to_malls' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'msg_firm_id_to_malls' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_msg_firm_id_to_malls * get_first_msg_firm_id_to_malls_message()
 * \brief Get the first msg_firm_id_to_malls message in the msg_firm_id_to_malls message list.
 * \return The first message in the list.
 */
m_msg_firm_id_to_malls * get_first_msg_firm_id_to_malls_message()
{
	return getInternalMessage_msg_firm_id_to_malls();
}

/** \fn xmachine_message_msg_firm_id_to_malls * get_next_msg_firm_id_to_malls_message(xmachine_message_msg_firm_id_to_malls * current)
 * \brief Get the next msg_firm_id_to_malls message in the msg_firm_id_to_malls message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_msg_firm_id_to_malls * get_next_msg_firm_id_to_malls_message(m_msg_firm_id_to_malls * current)
{
	return getInternalMessage_msg_firm_id_to_malls();
}


union pu_msg_mall_id_to_firms 
{
    m_msg_mall_id_to_firms *ptr;
    void *ptr_anon;
};

/** \fn void add_msg_mall_id_to_firms_message(int mall_id, int region_id)
 * \brief Add msg_mall_id_to_firms message by calling internal and processing.
 * \param mall_id Message variable.
 * \param region_id Message variable.
 */
void add_msg_mall_id_to_firms_message(int mall_id, int region_id)
{
    int rc;
	m_msg_mall_id_to_firms msg;
    
    msg.mall_id = mall_id;
    msg.region_id = region_id;
    
    
    rc = MB_AddMessage(b_msg_mall_id_to_firms, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'msg_mall_id_to_firms' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'msg_mall_id_to_firms' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'msg_mall_id_to_firms' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_msg_mall_id_to_firms* getInternalMessage_msg_mall_id_to_firms(void)
{
    static m_msg_mall_id_to_firms *msg_prev = NULL;
    union pu_msg_mall_id_to_firms msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_msg_mall_id_to_firms); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'msg_mall_id_to_firms' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'msg_mall_id_to_firms' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_msg_mall_id_to_firms, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'msg_mall_id_to_firms' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'msg_mall_id_to_firms' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_msg_mall_id_to_firms * get_first_msg_mall_id_to_firms_message()
 * \brief Get the first msg_mall_id_to_firms message in the msg_mall_id_to_firms message list.
 * \return The first message in the list.
 */
m_msg_mall_id_to_firms * get_first_msg_mall_id_to_firms_message()
{
	return getInternalMessage_msg_mall_id_to_firms();
}

/** \fn xmachine_message_msg_mall_id_to_firms * get_next_msg_mall_id_to_firms_message(xmachine_message_msg_mall_id_to_firms * current)
 * \brief Get the next msg_mall_id_to_firms message in the msg_mall_id_to_firms message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_msg_mall_id_to_firms * get_next_msg_mall_id_to_firms_message(m_msg_mall_id_to_firms * current)
{
	return getInternalMessage_msg_mall_id_to_firms();
}


union pu_msg_skills_eurostat_to_igfirm 
{
    m_msg_skills_eurostat_to_igfirm *ptr;
    void *ptr_anon;
};

/** \fn void add_msg_skills_eurostat_to_igfirm_message(double mean_general_skills, double mean_specific_skills, double productivity_progress, double total_capital_stock_units)
 * \brief Add msg_skills_eurostat_to_igfirm message by calling internal and processing.
 * \param mean_general_skills Message variable.
 * \param mean_specific_skills Message variable.
 * \param productivity_progress Message variable.
 * \param total_capital_stock_units Message variable.
 */
void add_msg_skills_eurostat_to_igfirm_message(double mean_general_skills, double mean_specific_skills, double productivity_progress, double total_capital_stock_units)
{
    int rc;
	m_msg_skills_eurostat_to_igfirm msg;
    
    msg.mean_general_skills = mean_general_skills;
    msg.mean_specific_skills = mean_specific_skills;
    msg.productivity_progress = productivity_progress;
    msg.total_capital_stock_units = total_capital_stock_units;
    
    
    rc = MB_AddMessage(b_msg_skills_eurostat_to_igfirm, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'msg_skills_eurostat_to_igfirm' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'msg_skills_eurostat_to_igfirm' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'msg_skills_eurostat_to_igfirm' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_msg_skills_eurostat_to_igfirm* getInternalMessage_msg_skills_eurostat_to_igfirm(void)
{
    static m_msg_skills_eurostat_to_igfirm *msg_prev = NULL;
    union pu_msg_skills_eurostat_to_igfirm msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_msg_skills_eurostat_to_igfirm); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'msg_skills_eurostat_to_igfirm' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'msg_skills_eurostat_to_igfirm' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_msg_skills_eurostat_to_igfirm, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'msg_skills_eurostat_to_igfirm' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'msg_skills_eurostat_to_igfirm' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_msg_skills_eurostat_to_igfirm * get_first_msg_skills_eurostat_to_igfirm_message()
 * \brief Get the first msg_skills_eurostat_to_igfirm message in the msg_skills_eurostat_to_igfirm message list.
 * \return The first message in the list.
 */
m_msg_skills_eurostat_to_igfirm * get_first_msg_skills_eurostat_to_igfirm_message()
{
	return getInternalMessage_msg_skills_eurostat_to_igfirm();
}

/** \fn xmachine_message_msg_skills_eurostat_to_igfirm * get_next_msg_skills_eurostat_to_igfirm_message(xmachine_message_msg_skills_eurostat_to_igfirm * current)
 * \brief Get the next msg_skills_eurostat_to_igfirm message in the msg_skills_eurostat_to_igfirm message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_msg_skills_eurostat_to_igfirm * get_next_msg_skills_eurostat_to_igfirm_message(m_msg_skills_eurostat_to_igfirm * current)
{
	return getInternalMessage_msg_skills_eurostat_to_igfirm();
}


union pu_msg_market_sizes 
{
    m_msg_market_sizes *ptr;
    void *ptr_anon;
};

/** \fn void add_msg_market_sizes_message(int region_id, double market_size, double government_demand)
 * \brief Add msg_market_sizes message by calling internal and processing.
 * \param region_id Message variable.
 * \param market_size Message variable.
 * \param government_demand Message variable.
 */
void add_msg_market_sizes_message(int region_id, double market_size, double government_demand)
{
    int rc;
	m_msg_market_sizes msg;
    
    msg.region_id = region_id;
    msg.market_size = market_size;
    msg.government_demand = government_demand;
    
    
    rc = MB_AddMessage(b_msg_market_sizes, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'msg_market_sizes' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'msg_market_sizes' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'msg_market_sizes' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_msg_market_sizes* getInternalMessage_msg_market_sizes(void)
{
    static m_msg_market_sizes *msg_prev = NULL;
    union pu_msg_market_sizes msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_msg_market_sizes); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'msg_market_sizes' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'msg_market_sizes' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_msg_market_sizes, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'msg_market_sizes' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'msg_market_sizes' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_msg_market_sizes * get_first_msg_market_sizes_message()
 * \brief Get the first msg_market_sizes message in the msg_market_sizes message list.
 * \return The first message in the list.
 */
m_msg_market_sizes * get_first_msg_market_sizes_message()
{
	return getInternalMessage_msg_market_sizes();
}

/** \fn xmachine_message_msg_market_sizes * get_next_msg_market_sizes_message(xmachine_message_msg_market_sizes * current)
 * \brief Get the next msg_market_sizes message in the msg_market_sizes message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_msg_market_sizes * get_next_msg_market_sizes_message(m_msg_market_sizes * current)
{
	return getInternalMessage_msg_market_sizes();
}


union pu_total_subsidies 
{
    m_total_subsidies *ptr;
    void *ptr_anon;
};

/** \fn void add_total_subsidies_message(int gov_id, int region_id, double amount)
 * \brief Add total_subsidies message by calling internal and processing.
 * \param gov_id Message variable.
 * \param region_id Message variable.
 * \param amount Message variable.
 */
void add_total_subsidies_message(int gov_id, int region_id, double amount)
{
    int rc;
	m_total_subsidies msg;
    
    msg.gov_id = gov_id;
    msg.region_id = region_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_total_subsidies, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'total_subsidies' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'total_subsidies' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'total_subsidies' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_total_subsidies* getInternalMessage_total_subsidies(void)
{
    static m_total_subsidies *msg_prev = NULL;
    union pu_total_subsidies msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_total_subsidies); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'total_subsidies' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'total_subsidies' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_total_subsidies, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'total_subsidies' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'total_subsidies' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_total_subsidies * get_first_total_subsidies_message()
 * \brief Get the first total_subsidies message in the total_subsidies message list.
 * \return The first message in the list.
 */
m_total_subsidies * get_first_total_subsidies_message()
{
	return getInternalMessage_total_subsidies();
}

/** \fn xmachine_message_total_subsidies * get_next_total_subsidies_message(xmachine_message_total_subsidies * current)
 * \brief Get the next total_subsidies message in the total_subsidies message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_total_subsidies * get_next_total_subsidies_message(m_total_subsidies * current)
{
	return getInternalMessage_total_subsidies();
}


union pu_redistributed_subsidies 
{
    m_redistributed_subsidies *ptr;
    void *ptr_anon;
};

/** \fn void add_redistributed_subsidies_message(int gov_id, double amount)
 * \brief Add redistributed_subsidies message by calling internal and processing.
 * \param gov_id Message variable.
 * \param amount Message variable.
 */
void add_redistributed_subsidies_message(int gov_id, double amount)
{
    int rc;
	m_redistributed_subsidies msg;
    
    msg.gov_id = gov_id;
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_redistributed_subsidies, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'redistributed_subsidies' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'redistributed_subsidies' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'redistributed_subsidies' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_redistributed_subsidies* getInternalMessage_redistributed_subsidies(void)
{
    static m_redistributed_subsidies *msg_prev = NULL;
    union pu_redistributed_subsidies msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_redistributed_subsidies); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'redistributed_subsidies' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'redistributed_subsidies' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_redistributed_subsidies, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'redistributed_subsidies' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'redistributed_subsidies' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_redistributed_subsidies * get_first_redistributed_subsidies_message()
 * \brief Get the first redistributed_subsidies message in the redistributed_subsidies message list.
 * \return The first message in the list.
 */
m_redistributed_subsidies * get_first_redistributed_subsidies_message()
{
	return getInternalMessage_redistributed_subsidies();
}

/** \fn xmachine_message_redistributed_subsidies * get_next_redistributed_subsidies_message(xmachine_message_redistributed_subsidies * current)
 * \brief Get the next redistributed_subsidies message in the redistributed_subsidies message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_redistributed_subsidies * get_next_redistributed_subsidies_message(m_redistributed_subsidies * current)
{
	return getInternalMessage_redistributed_subsidies();
}


union pu_quality_price 
{
    m_quality_price *ptr;
    void *ptr_anon;
};

/** \fn void add_quality_price_message(int region_id, double quality, double price)
 * \brief Add quality_price message by calling internal and processing.
 * \param region_id Message variable.
 * \param quality Message variable.
 * \param price Message variable.
 */
void add_quality_price_message(int region_id, double quality, double price)
{
    int rc;
	m_quality_price msg;
    
    msg.region_id = region_id;
    msg.quality = quality;
    msg.price = price;
    
    
    rc = MB_AddMessage(b_quality_price, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'quality_price' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quality_price' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_quality_price* getInternalMessage_quality_price(void)
{
    static m_quality_price *msg_prev = NULL;
    union pu_quality_price msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_quality_price); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'quality_price' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'quality_price' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_quality_price, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'quality_price' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_quality_price * get_first_quality_price_message()
 * \brief Get the first quality_price message in the quality_price message list.
 * \return The first message in the list.
 */
m_quality_price * get_first_quality_price_message()
{
	return getInternalMessage_quality_price();
}

/** \fn xmachine_message_quality_price * get_next_quality_price_message(xmachine_message_quality_price * current)
 * \brief Get the next quality_price message in the quality_price message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_quality_price * get_next_quality_price_message(m_quality_price * current)
{
	return getInternalMessage_quality_price();
}


union pu_interview_request 
{
    m_interview_request *ptr;
    void *ptr_anon;
};

/** \fn void add_interview_request_message(int firm_id)
 * \brief Add interview_request message by calling internal and processing.
 * \param firm_id Message variable.
 */
void add_interview_request_message(int firm_id)
{
    int rc;
	m_interview_request msg;
    
    msg.firm_id = firm_id;
    
    
    rc = MB_AddMessage(b_interview_request, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'interview_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'interview_request' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'interview_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_interview_request* getInternalMessage_interview_request(void)
{
    static m_interview_request *msg_prev = NULL;
    union pu_interview_request msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_interview_request); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'interview_request' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'interview_request' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_interview_request, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'interview_request' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'interview_request' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_interview_request * get_first_interview_request_message()
 * \brief Get the first interview_request message in the interview_request message list.
 * \return The first message in the list.
 */
m_interview_request * get_first_interview_request_message()
{
	return getInternalMessage_interview_request();
}

/** \fn xmachine_message_interview_request * get_next_interview_request_message(xmachine_message_interview_request * current)
 * \brief Get the next interview_request message in the interview_request message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_interview_request * get_next_interview_request_message(m_interview_request * current)
{
	return getInternalMessage_interview_request();
}


union pu_interview_positive_response 
{
    m_interview_positive_response *ptr;
    void *ptr_anon;
};

/** \fn void add_interview_positive_response_message(int id, int region_id, int firm_id)
 * \brief Add interview_positive_response message by calling internal and processing.
 * \param id Message variable.
 * \param region_id Message variable.
 * \param firm_id Message variable.
 */
void add_interview_positive_response_message(int id, int region_id, int firm_id)
{
    int rc;
	m_interview_positive_response msg;
    
    msg.id = id;
    msg.region_id = region_id;
    msg.firm_id = firm_id;
    
    
    rc = MB_AddMessage(b_interview_positive_response, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'interview_positive_response' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'interview_positive_response' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'interview_positive_response' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_interview_positive_response* getInternalMessage_interview_positive_response(void)
{
    static m_interview_positive_response *msg_prev = NULL;
    union pu_interview_positive_response msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_interview_positive_response); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'interview_positive_response' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'interview_positive_response' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_interview_positive_response, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'interview_positive_response' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'interview_positive_response' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_interview_positive_response * get_first_interview_positive_response_message()
 * \brief Get the first interview_positive_response message in the interview_positive_response message list.
 * \return The first message in the list.
 */
m_interview_positive_response * get_first_interview_positive_response_message()
{
	return getInternalMessage_interview_positive_response();
}

/** \fn xmachine_message_interview_positive_response * get_next_interview_positive_response_message(xmachine_message_interview_positive_response * current)
 * \brief Get the next interview_positive_response message in the interview_positive_response message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_interview_positive_response * get_next_interview_positive_response_message(m_interview_positive_response * current)
{
	return getInternalMessage_interview_positive_response();
}


union pu_questionnaire_innovation 
{
    m_questionnaire_innovation *ptr;
    void *ptr_anon;
};

/** \fn void add_questionnaire_innovation_message(int firm_id, price_quality_pair price_quality)
 * \brief Add questionnaire_innovation message by calling internal and processing.
 * \param firm_id Message variable.
 * \param price_quality Message variable.
 */
void add_questionnaire_innovation_message(int firm_id, price_quality_pair price_quality[])
{
    int rc;
	m_questionnaire_innovation msg;
    
    msg.firm_id = firm_id;
    copy_price_quality_pair_static_array(price_quality, msg.price_quality, 12);
    
    
    rc = MB_AddMessage(b_questionnaire_innovation, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'questionnaire_innovation' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'questionnaire_innovation' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'questionnaire_innovation' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_questionnaire_innovation* getInternalMessage_questionnaire_innovation(void)
{
    static m_questionnaire_innovation *msg_prev = NULL;
    union pu_questionnaire_innovation msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_questionnaire_innovation); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'questionnaire_innovation' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'questionnaire_innovation' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_questionnaire_innovation, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'questionnaire_innovation' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'questionnaire_innovation' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_questionnaire_innovation * get_first_questionnaire_innovation_message()
 * \brief Get the first questionnaire_innovation message in the questionnaire_innovation message list.
 * \return The first message in the list.
 */
m_questionnaire_innovation * get_first_questionnaire_innovation_message()
{
	return getInternalMessage_questionnaire_innovation();
}

/** \fn xmachine_message_questionnaire_innovation * get_next_questionnaire_innovation_message(xmachine_message_questionnaire_innovation * current)
 * \brief Get the next questionnaire_innovation message in the questionnaire_innovation message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_questionnaire_innovation * get_next_questionnaire_innovation_message(m_questionnaire_innovation * current)
{
	return getInternalMessage_questionnaire_innovation();
}


union pu_filled_out_questionnaire_product_innovation 
{
    m_filled_out_questionnaire_product_innovation *ptr;
    void *ptr_anon;
};

/** \fn void add_filled_out_questionnaire_product_innovation_message(int firm_id, int region_id, int choice)
 * \brief Add filled_out_questionnaire_product_innovation message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param choice Message variable.
 */
void add_filled_out_questionnaire_product_innovation_message(int firm_id, int region_id, int choice)
{
    int rc;
	m_filled_out_questionnaire_product_innovation msg;
    
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.choice = choice;
    
    
    rc = MB_AddMessage(b_filled_out_questionnaire_product_innovation, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'filled_out_questionnaire_product_innovation' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'filled_out_questionnaire_product_innovation' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'filled_out_questionnaire_product_innovation' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_filled_out_questionnaire_product_innovation* getInternalMessage_filled_out_questionnaire_product_innovation(void)
{
    static m_filled_out_questionnaire_product_innovation *msg_prev = NULL;
    union pu_filled_out_questionnaire_product_innovation msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_filled_out_questionnaire_product_innovation); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'filled_out_questionnaire_product_innovation' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'filled_out_questionnaire_product_innovation' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_filled_out_questionnaire_product_innovation, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'filled_out_questionnaire_product_innovation' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'filled_out_questionnaire_product_innovation' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_filled_out_questionnaire_product_innovation * get_first_filled_out_questionnaire_product_innovation_message()
 * \brief Get the first filled_out_questionnaire_product_innovation message in the filled_out_questionnaire_product_innovation message list.
 * \return The first message in the list.
 */
m_filled_out_questionnaire_product_innovation * get_first_filled_out_questionnaire_product_innovation_message()
{
	return getInternalMessage_filled_out_questionnaire_product_innovation();
}

/** \fn xmachine_message_filled_out_questionnaire_product_innovation * get_next_filled_out_questionnaire_product_innovation_message(xmachine_message_filled_out_questionnaire_product_innovation * current)
 * \brief Get the next filled_out_questionnaire_product_innovation message in the filled_out_questionnaire_product_innovation message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_filled_out_questionnaire_product_innovation * get_next_filled_out_questionnaire_product_innovation_message(m_filled_out_questionnaire_product_innovation * current)
{
	return getInternalMessage_filled_out_questionnaire_product_innovation();
}

