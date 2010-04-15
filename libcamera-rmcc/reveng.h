/* Reverse engineered, probed, guessed, or otherwise undocumented structs
 * and macros */

#define MSM_CAMERA "/dev/msm_camera"

#define CAM_CTRL_SUCCESS 1

#define CAMERA_SET_PARM_DIMENSION 1
#define CAMERA_SET_PARM_WB 14
#define CAMERA_SET_PARM_AUTO_FOCUS 13
#define CAMERA_SET_PARM_EFFECT 15
#define CAMERA_SET_PARM_ANTIBANDING 21
#define CAMERA_START_PREVIEW 37
#define CAMERA_STOP_PREVIEW 36
#define CAMERA_START_RAW_SNAPSHOT 39
#define CAMERA_START_SNAPSHOT 38
#define CAMERA_STOP_SNAPSHOT 40
#define CAMERA_EXIT 41

// Confirmed:
// 36: CAMERA_STOP_PREVIEW
// 37: CAMERA_START_PREVIEW
// 38: CAMERA_START_SNAPSHOT
// 39: CAMERA_START_RAW_SNAPSHOT
// 40: CAMERA_STOP_SNAPSHOT
// 41: CAMERA_EXIT
//


#define AF_MODE_AUTO 2
#define CAMERA_AUTO_FOCUS_CANCEL 1 //204


#define THUMBNAIL_WIDTH        512
#define THUMBNAIL_HEIGHT       384
#define PICTURE_WIDTH  2048 // 1280
#define PICTURE_HEIGHT 1536 // 768
#define THUMBNAIL_BUFFER_SIZE (THUMBNAIL_WIDTH * THUMBNAIL_HEIGHT * 3/2)


typedef struct
{
    unsigned short picture_width;
    unsigned short picture_height;
    unsigned short display_width;
    unsigned short display_height;
    unsigned short orig_picture_dx;
    unsigned short orig_picture_dy;
    unsigned short ui_thumbnail_height;
    unsigned short ui_thumbnail_width;
    unsigned short thumbnail_height;
    unsigned short thumbnail_width;
    unsigned short filler5;
    unsigned short filler6;
    unsigned short filler7;
    unsigned short filler8;
} cam_ctrl_dimension_t;

typedef enum
{
    CAMERA_WB_MIN_MINUS_1,
    CAMERA_WB_AUTO = 1,  /* This list must match aeecamera.h */
    CAMERA_WB_CUSTOM,
    CAMERA_WB_INCANDESCENT,
    CAMERA_WB_FLUORESCENT,
    CAMERA_WB_DAYLIGHT,
    CAMERA_WB_CLOUDY_DAYLIGHT,
    CAMERA_WB_TWILIGHT,
    CAMERA_WB_SHADE,
    CAMERA_WB_MAX_PLUS_1
} camera_wb_type;

typedef enum
{
    CAMERA_RSP_CB_SUCCESS,    /* Function is accepted         */
    CAMERA_EXIT_CB_DONE,      /* Function is executed         */
    CAMERA_EXIT_CB_FAILED,    /* Execution failed or rejected */
    CAMERA_EXIT_CB_DSP_IDLE,  /* DSP is in idle state         */
    CAMERA_EXIT_CB_DSP_ABORT, /* Abort due to DSP failure     */
    CAMERA_EXIT_CB_ABORT,     /* Function aborted             */
    CAMERA_EXIT_CB_ERROR,     /* Failed due to resource       */
    CAMERA_EVT_CB_FRAME,      /* Preview or video frame ready */
    CAMERA_EVT_CB_PICTURE,    /* Picture frame ready for multi-shot */
    CAMERA_STATUS_CB,         /* Status updated               */
    CAMERA_EXIT_CB_FILE_SIZE_EXCEEDED, /* Specified file size not achieved,
                                          encoded file written & returned anyway */
    CAMERA_EXIT_CB_BUFFER,    /* A buffer is returned         */
    CAMERA_EVT_CB_SNAPSHOT_DONE,/*  Snapshot updated               */
    CAMERA_CB_MAX
} camera_cb_type;

typedef enum
{
    CAMERA_ANTIBANDING_OFF,
    CAMERA_ANTIBANDING_60HZ,
    CAMERA_ANTIBANDING_50HZ,
    CAMERA_ANTIBANDING_AUTO,
    CAMERA_MAX_ANTIBANDING,
} camera_antibanding_type;

typedef struct
{
    uint32_t timestamp;  /* seconds since 1/6/1980          */
    double   latitude;   /* degrees, WGS ellipsoid */
    double   longitude;  /* degrees                */
    int16_t  altitude;   /* meters                          */
} camera_position_type;

typedef struct
{
    uint8_t update_flag;
    unsigned int in1_w;
    unsigned int in1_h;
    unsigned int out1_w;
    unsigned int out1_h;
    unsigned int in2_w;
    unsigned int in2_h;
    unsigned int out2_w;
    unsigned int out2_h;
} common_crop_t;

typedef struct
{
    unsigned int maximum_value;
    unsigned int minimum_value;
    unsigned int current_value;
    unsigned int step_value;
} cam_parm_info_t;

typedef unsigned int isp3a_af_mode_t;
typedef uint8_t cam_ctrl_type;
typedef uint8_t jpeg_event_t;

#define JPEG_EVENT_DONE 0

#define CEILING16(x)  (((x)+0xf)&~0xf)
