#define SET_BIT(VAR,BIT_NO) (VAR|=(1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO) ((VAR>>BIT_NO)&1)
#define CLR_BIT(VAR,BIT_NO) (VAR&=(~(1<<BIT_NO)))
#define TOG_BIT(VAR,BIT_NO) (VAR^=(1<<BIT_NO))

