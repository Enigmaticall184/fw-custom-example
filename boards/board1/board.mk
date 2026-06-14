ifneq ($(PROJECT_CPU),simulator)

CDEFS += -DTS_SECONDARY_UxART_PORT=SD3

BOARDCPPSRC += \
    $(BOARD_DIR)/board_configuration.cpp \

endif
