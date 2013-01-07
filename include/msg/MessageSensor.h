#ifndef UAVLINK_MESSAGE_SENSOR_H
#define UAVLINK_MESSAGE_SENSOR_H

/*----------------------------------------------------
 # SENSORS
 #--------------------------------------------------*/

#define UAVLINK_MSG_SENSOR_LEN 18
typedef struct __uavlink_message_sensor {
    int16_t accX;
    int16_t accY;
    int16_t accZ;
    int16_t gyroX;
    int16_t gyroY;
    int16_t gyroZ;
    int16_t roll;
    int16_t pitch;
    int16_t yaw;
} uavlink_message_sensor_t;

inline static void uavlink_message_sensor_decode(const uavlink_message_t* msg, uavlink_message_sensor_t* sensor)
{

#ifdef PROCOTOL_BITSWAP
    sensor->accX = _UAVLINK_RETURN_uint16_t(msg,0);
    sensor->accY = _UAVLINK_RETURN_uint16_t(msg,2);
    sensor->accZ = _UAVLINK_RETURN_uint16_t(msg,4);
    sensor->gyroX = _UAVLINK_RETURN_uint16_t(msg,6);
    sensor->gyroY = _UAVLINK_RETURN_uint16_t(msg,8);
    sensor->gyroZ = _UAVLINK_RETURN_uint16_t(msg,10);
    sensor->roll = _UAVLINK_RETURN_uint16_t(msg,12);
    sensor->pitch = _UAVLINK_RETURN_uint16_t(msg,14);
    sensor->yaw = _UAVLINK_RETURN_uint16_t(msg,16);
#else
    memcpy(sensor, _UAVLINK_PAYLOAD(msg), UAVLINK_MSG_SENSOR_LEN);
#endif
}

inline static const uavlink_message_t uavlink_message_sensor_encode(uavlink_message_sensor_t* sensor)
{
    uavlink_message_t msg;
    msg.cmd = UAVLINK_MSG_SENSOR;
    msg.len = UAVLINK_MSG_SENSOR_LEN;
    memcpy(&msg.datas[0],sensor, UAVLINK_MSG_SENSOR_LEN);

    return msg;
}

#endif // UAVLINK_MESSAGE_SENSOR_H