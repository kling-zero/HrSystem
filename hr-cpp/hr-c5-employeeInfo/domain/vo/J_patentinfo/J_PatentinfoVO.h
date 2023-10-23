#ifndef _J_PATENT_VO_
#define _J_PATENT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/J_patentinfo/J_PatentinfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * ר����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class J_PatentinfoJsonVO : public JsonVO<J_PatentinfoDTO::Wrapper> {
	DTO_INIT(J_PatentinfoJsonVO, JsonVO<J_PatentinfoDTO::Wrapper>);
};




/**
 * ר����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */ 
class J_PatentinfoPageJsonVO : public JsonVO<J_PatentinfoPageDTO::Wrapper> {
	DTO_INIT(J_PatentinfoPageJsonVO, JsonVO<J_PatentinfoPageDTO::Wrapper>);
};





#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_