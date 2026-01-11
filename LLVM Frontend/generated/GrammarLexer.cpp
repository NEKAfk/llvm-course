
// Generated from Grammar.g4 by ANTLR 4.13.2


#include "GrammarLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct GrammarLexerStaticData final {
  GrammarLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  GrammarLexerStaticData(const GrammarLexerStaticData&) = delete;
  GrammarLexerStaticData(GrammarLexerStaticData&&) = delete;
  GrammarLexerStaticData& operator=(const GrammarLexerStaticData&) = delete;
  GrammarLexerStaticData& operator=(GrammarLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag grammarlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<GrammarLexerStaticData> grammarlexerLexerStaticData = nullptr;

void grammarlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (grammarlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(grammarlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<GrammarLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "NUM", 
      "VOID", "TERN_OP", "BIN_OP", "ID", "INT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'let'", "'('", "')'", "'->'", "'='", "'{'", "'}'", "';'", "'for'", 
      "'['", "','", "']'", "'if'", "'while'", "'arr'", "'return'", "'num'", 
      "'void'", "'\\u003F'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "NUM", "VOID", "TERN_OP", "BIN_OP", "ID", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,23,146,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,4,1,4,1,
  	5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,
  	1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,
  	1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,118,
  	8,19,1,20,1,20,5,20,122,8,20,10,20,12,20,125,9,20,1,21,3,21,128,8,21,
  	1,21,1,21,1,21,5,21,133,8,21,10,21,12,21,136,9,21,3,21,138,8,21,1,22,
  	4,22,141,8,22,11,22,12,22,142,1,22,1,22,0,0,23,1,1,3,2,5,3,7,4,9,5,11,
  	6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,
  	37,19,39,20,41,21,43,22,45,23,1,0,7,3,0,37,37,42,43,124,124,2,0,38,38,
  	47,47,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,0,49,57,1,
  	0,48,57,3,0,9,10,13,13,32,32,155,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,
  	0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,
  	0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,
  	0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,
  	39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,1,47,1,0,0,0,3,51,1,
  	0,0,0,5,53,1,0,0,0,7,55,1,0,0,0,9,58,1,0,0,0,11,60,1,0,0,0,13,62,1,0,
  	0,0,15,64,1,0,0,0,17,66,1,0,0,0,19,70,1,0,0,0,21,72,1,0,0,0,23,74,1,0,
  	0,0,25,76,1,0,0,0,27,79,1,0,0,0,29,85,1,0,0,0,31,89,1,0,0,0,33,96,1,0,
  	0,0,35,100,1,0,0,0,37,105,1,0,0,0,39,117,1,0,0,0,41,119,1,0,0,0,43,127,
  	1,0,0,0,45,140,1,0,0,0,47,48,5,108,0,0,48,49,5,101,0,0,49,50,5,116,0,
  	0,50,2,1,0,0,0,51,52,5,40,0,0,52,4,1,0,0,0,53,54,5,41,0,0,54,6,1,0,0,
  	0,55,56,5,45,0,0,56,57,5,62,0,0,57,8,1,0,0,0,58,59,5,61,0,0,59,10,1,0,
  	0,0,60,61,5,123,0,0,61,12,1,0,0,0,62,63,5,125,0,0,63,14,1,0,0,0,64,65,
  	5,59,0,0,65,16,1,0,0,0,66,67,5,102,0,0,67,68,5,111,0,0,68,69,5,114,0,
  	0,69,18,1,0,0,0,70,71,5,91,0,0,71,20,1,0,0,0,72,73,5,44,0,0,73,22,1,0,
  	0,0,74,75,5,93,0,0,75,24,1,0,0,0,76,77,5,105,0,0,77,78,5,102,0,0,78,26,
  	1,0,0,0,79,80,5,119,0,0,80,81,5,104,0,0,81,82,5,105,0,0,82,83,5,108,0,
  	0,83,84,5,101,0,0,84,28,1,0,0,0,85,86,5,97,0,0,86,87,5,114,0,0,87,88,
  	5,114,0,0,88,30,1,0,0,0,89,90,5,114,0,0,90,91,5,101,0,0,91,92,5,116,0,
  	0,92,93,5,117,0,0,93,94,5,114,0,0,94,95,5,110,0,0,95,32,1,0,0,0,96,97,
  	5,110,0,0,97,98,5,117,0,0,98,99,5,109,0,0,99,34,1,0,0,0,100,101,5,118,
  	0,0,101,102,5,111,0,0,102,103,5,105,0,0,103,104,5,100,0,0,104,36,1,0,
  	0,0,105,106,5,63,0,0,106,38,1,0,0,0,107,108,5,61,0,0,108,118,5,61,0,0,
  	109,110,5,33,0,0,110,118,5,61,0,0,111,112,5,124,0,0,112,118,5,124,0,0,
  	113,118,7,0,0,0,114,115,5,38,0,0,115,118,5,38,0,0,116,118,7,1,0,0,117,
  	107,1,0,0,0,117,109,1,0,0,0,117,111,1,0,0,0,117,113,1,0,0,0,117,114,1,
  	0,0,0,117,116,1,0,0,0,118,40,1,0,0,0,119,123,7,2,0,0,120,122,7,3,0,0,
  	121,120,1,0,0,0,122,125,1,0,0,0,123,121,1,0,0,0,123,124,1,0,0,0,124,42,
  	1,0,0,0,125,123,1,0,0,0,126,128,5,45,0,0,127,126,1,0,0,0,127,128,1,0,
  	0,0,128,137,1,0,0,0,129,138,5,48,0,0,130,134,7,4,0,0,131,133,7,5,0,0,
  	132,131,1,0,0,0,133,136,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,138,
  	1,0,0,0,136,134,1,0,0,0,137,129,1,0,0,0,137,130,1,0,0,0,138,44,1,0,0,
  	0,139,141,7,6,0,0,140,139,1,0,0,0,141,142,1,0,0,0,142,140,1,0,0,0,142,
  	143,1,0,0,0,143,144,1,0,0,0,144,145,6,22,0,0,145,46,1,0,0,0,7,0,117,123,
  	127,134,137,142,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  grammarlexerLexerStaticData = std::move(staticData);
}

}

GrammarLexer::GrammarLexer(CharStream *input) : Lexer(input) {
  GrammarLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *grammarlexerLexerStaticData->atn, grammarlexerLexerStaticData->decisionToDFA, grammarlexerLexerStaticData->sharedContextCache);
}

GrammarLexer::~GrammarLexer() {
  delete _interpreter;
}

std::string GrammarLexer::getGrammarFileName() const {
  return "Grammar.g4";
}

const std::vector<std::string>& GrammarLexer::getRuleNames() const {
  return grammarlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& GrammarLexer::getChannelNames() const {
  return grammarlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& GrammarLexer::getModeNames() const {
  return grammarlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& GrammarLexer::getVocabulary() const {
  return grammarlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView GrammarLexer::getSerializedATN() const {
  return grammarlexerLexerStaticData->serializedATN;
}

const atn::ATN& GrammarLexer::getATN() const {
  return *grammarlexerLexerStaticData->atn;
}




void GrammarLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  grammarlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(grammarlexerLexerOnceFlag, grammarlexerLexerInitialize);
#endif
}
