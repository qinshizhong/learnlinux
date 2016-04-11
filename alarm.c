#include "alarm.h"


static alarm_t m_alarm[MAX_ALARM_NUM];


void alarm_init(void)
{
    memset(m_alarm, 0, sizeof(m_alarm));
}


uint32_t alarm_create(alarm_time_t *p_alarm_time)
{
    ASSERT(p_alarm_time != NULL);

    uint32_t err_code = NRF_ERROR_NULL;

    if (p_alarm_time != NULL) {
        for (uint32_t i = 0; i < MAX_ALARM_NUM; ++i) {
            if (0 == m_alarm[i].used) {
                m_alarm[i].used = NODE_USED;
                m_alarm[i].time.hour = p_alarm_time->hour;
                m_alarm[i].time.min  = p_alarm_time->min;
                m_alarm[i].time.sec  = p_alarm_time->sec;
            }
        }
    }

    return err_code;
}   
