
// Generated from Grammar.g4 by ANTLR 4.13.2


#include "GrammarListener.h"
#include "GrammarVisitor.h"

#include "GrammarParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct GrammarParserStaticData final {
  GrammarParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  GrammarParserStaticData(const GrammarParserStaticData&) = delete;
  GrammarParserStaticData(GrammarParserStaticData&&) = delete;
  GrammarParserStaticData& operator=(const GrammarParserStaticData&) = delete;
  GrammarParserStaticData& operator=(GrammarParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag grammarParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<GrammarParserStaticData> grammarParserStaticData = nullptr;

void grammarParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (grammarParserStaticData != nullptr) {
    return;
  }
#else
  assert(grammarParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<GrammarParserStaticData>(
    std::vector<std::string>{
      "program", "funDecl", "line", "forExpr", "ifExpr", "whileExpr", "expr", 
      "funParams", "assign", "create", "varDecl", "arrDecl", "returnExpr"
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
  	4,1,23,204,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,1,0,4,0,28,8,0,11,
  	0,12,0,29,1,0,1,0,1,1,1,1,1,1,1,1,5,1,38,8,1,10,1,12,1,41,9,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,4,1,49,8,1,11,1,12,1,50,1,1,1,1,1,2,1,2,1,2,1,2,3,2,59,
  	8,2,1,2,1,2,1,2,1,2,1,2,3,2,66,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,4,3,77,8,3,11,3,12,3,78,1,3,1,3,4,3,83,8,3,11,3,12,3,84,1,3,1,3,1,4,
  	1,4,1,4,1,4,1,4,1,4,4,4,95,8,4,11,4,12,4,96,1,4,1,4,1,5,1,5,1,5,1,5,1,
  	5,1,5,4,5,107,8,5,11,5,12,5,108,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,
  	6,120,8,6,10,6,12,6,123,9,6,1,6,1,6,3,6,127,8,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,146,8,6,1,7,1,7,1,7,
  	1,7,5,7,152,8,7,10,7,12,7,155,9,7,3,7,157,8,7,1,7,1,7,1,8,1,8,1,8,1,8,
  	1,8,5,8,166,8,8,10,8,12,8,169,9,8,1,8,1,8,3,8,173,8,8,1,8,1,8,1,8,1,9,
  	1,9,3,9,180,8,9,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,5,11,
  	192,8,11,10,11,12,11,195,9,11,1,11,1,11,1,11,1,12,1,12,3,12,202,8,12,
  	1,12,0,0,13,0,2,4,6,8,10,12,14,16,18,20,22,24,0,1,1,0,17,18,216,0,27,
  	1,0,0,0,2,33,1,0,0,0,4,65,1,0,0,0,6,67,1,0,0,0,8,88,1,0,0,0,10,100,1,
  	0,0,0,12,145,1,0,0,0,14,147,1,0,0,0,16,160,1,0,0,0,18,179,1,0,0,0,20,
  	181,1,0,0,0,22,186,1,0,0,0,24,199,1,0,0,0,26,28,3,2,1,0,27,26,1,0,0,0,
  	28,29,1,0,0,0,29,27,1,0,0,0,29,30,1,0,0,0,30,31,1,0,0,0,31,32,5,0,0,1,
  	32,1,1,0,0,0,33,34,5,1,0,0,34,35,5,21,0,0,35,39,5,2,0,0,36,38,5,21,0,
  	0,37,36,1,0,0,0,38,41,1,0,0,0,39,37,1,0,0,0,39,40,1,0,0,0,40,42,1,0,0,
  	0,41,39,1,0,0,0,42,43,5,3,0,0,43,44,5,4,0,0,44,45,7,0,0,0,45,46,5,5,0,
  	0,46,48,5,6,0,0,47,49,3,4,2,0,48,47,1,0,0,0,49,50,1,0,0,0,50,48,1,0,0,
  	0,50,51,1,0,0,0,51,52,1,0,0,0,52,53,5,7,0,0,53,3,1,0,0,0,54,59,3,12,6,
  	0,55,59,3,16,8,0,56,59,3,18,9,0,57,59,3,24,12,0,58,54,1,0,0,0,58,55,1,
  	0,0,0,58,56,1,0,0,0,58,57,1,0,0,0,59,60,1,0,0,0,60,61,5,8,0,0,61,66,1,
  	0,0,0,62,66,3,6,3,0,63,66,3,8,4,0,64,66,3,10,5,0,65,58,1,0,0,0,65,62,
  	1,0,0,0,65,63,1,0,0,0,65,64,1,0,0,0,66,5,1,0,0,0,67,76,5,9,0,0,68,69,
  	5,10,0,0,69,70,5,21,0,0,70,71,5,11,0,0,71,72,3,12,6,0,72,73,5,11,0,0,
  	73,74,3,12,6,0,74,75,5,12,0,0,75,77,1,0,0,0,76,68,1,0,0,0,77,78,1,0,0,
  	0,78,76,1,0,0,0,78,79,1,0,0,0,79,80,1,0,0,0,80,82,5,6,0,0,81,83,3,4,2,
  	0,82,81,1,0,0,0,83,84,1,0,0,0,84,82,1,0,0,0,84,85,1,0,0,0,85,86,1,0,0,
  	0,86,87,5,7,0,0,87,7,1,0,0,0,88,89,5,13,0,0,89,90,5,10,0,0,90,91,3,12,
  	6,0,91,92,5,12,0,0,92,94,5,6,0,0,93,95,3,4,2,0,94,93,1,0,0,0,95,96,1,
  	0,0,0,96,94,1,0,0,0,96,97,1,0,0,0,97,98,1,0,0,0,98,99,5,7,0,0,99,9,1,
  	0,0,0,100,101,5,14,0,0,101,102,5,10,0,0,102,103,3,12,6,0,103,104,5,12,
  	0,0,104,106,5,6,0,0,105,107,3,4,2,0,106,105,1,0,0,0,107,108,1,0,0,0,108,
  	106,1,0,0,0,108,109,1,0,0,0,109,110,1,0,0,0,110,111,5,7,0,0,111,11,1,
  	0,0,0,112,113,5,21,0,0,113,146,3,14,7,0,114,126,5,21,0,0,115,116,5,10,
  	0,0,116,121,3,12,6,0,117,118,5,11,0,0,118,120,3,12,6,0,119,117,1,0,0,
  	0,120,123,1,0,0,0,121,119,1,0,0,0,121,122,1,0,0,0,122,124,1,0,0,0,123,
  	121,1,0,0,0,124,125,5,12,0,0,125,127,1,0,0,0,126,115,1,0,0,0,126,127,
  	1,0,0,0,127,146,1,0,0,0,128,129,5,19,0,0,129,130,5,2,0,0,130,131,3,12,
  	6,0,131,132,5,11,0,0,132,133,3,12,6,0,133,134,5,11,0,0,134,135,3,12,6,
  	0,135,136,5,3,0,0,136,146,1,0,0,0,137,138,5,20,0,0,138,139,5,2,0,0,139,
  	140,3,12,6,0,140,141,5,11,0,0,141,142,3,12,6,0,142,143,5,3,0,0,143,146,
  	1,0,0,0,144,146,5,22,0,0,145,112,1,0,0,0,145,114,1,0,0,0,145,128,1,0,
  	0,0,145,137,1,0,0,0,145,144,1,0,0,0,146,13,1,0,0,0,147,156,5,2,0,0,148,
  	153,3,12,6,0,149,150,5,11,0,0,150,152,3,12,6,0,151,149,1,0,0,0,152,155,
  	1,0,0,0,153,151,1,0,0,0,153,154,1,0,0,0,154,157,1,0,0,0,155,153,1,0,0,
  	0,156,148,1,0,0,0,156,157,1,0,0,0,157,158,1,0,0,0,158,159,5,3,0,0,159,
  	15,1,0,0,0,160,172,5,21,0,0,161,162,5,10,0,0,162,167,3,12,6,0,163,164,
  	5,11,0,0,164,166,3,12,6,0,165,163,1,0,0,0,166,169,1,0,0,0,167,165,1,0,
  	0,0,167,168,1,0,0,0,168,170,1,0,0,0,169,167,1,0,0,0,170,171,5,12,0,0,
  	171,173,1,0,0,0,172,161,1,0,0,0,172,173,1,0,0,0,173,174,1,0,0,0,174,175,
  	5,5,0,0,175,176,3,12,6,0,176,17,1,0,0,0,177,180,3,20,10,0,178,180,3,22,
  	11,0,179,177,1,0,0,0,179,178,1,0,0,0,180,19,1,0,0,0,181,182,5,17,0,0,
  	182,183,5,21,0,0,183,184,5,5,0,0,184,185,3,12,6,0,185,21,1,0,0,0,186,
  	187,5,15,0,0,187,188,5,10,0,0,188,193,5,22,0,0,189,190,5,11,0,0,190,192,
  	5,22,0,0,191,189,1,0,0,0,192,195,1,0,0,0,193,191,1,0,0,0,193,194,1,0,
  	0,0,194,196,1,0,0,0,195,193,1,0,0,0,196,197,5,12,0,0,197,198,5,21,0,0,
  	198,23,1,0,0,0,199,201,5,16,0,0,200,202,3,12,6,0,201,200,1,0,0,0,201,
  	202,1,0,0,0,202,25,1,0,0,0,19,29,39,50,58,65,78,84,96,108,121,126,145,
  	153,156,167,172,179,193,201
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  grammarParserStaticData = std::move(staticData);
}

}

GrammarParser::GrammarParser(TokenStream *input) : GrammarParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

GrammarParser::GrammarParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  GrammarParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *grammarParserStaticData->atn, grammarParserStaticData->decisionToDFA, grammarParserStaticData->sharedContextCache, options);
}

GrammarParser::~GrammarParser() {
  delete _interpreter;
}

const atn::ATN& GrammarParser::getATN() const {
  return *grammarParserStaticData->atn;
}

std::string GrammarParser::getGrammarFileName() const {
  return "Grammar.g4";
}

const std::vector<std::string>& GrammarParser::getRuleNames() const {
  return grammarParserStaticData->ruleNames;
}

const dfa::Vocabulary& GrammarParser::getVocabulary() const {
  return grammarParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView GrammarParser::getSerializedATN() const {
  return grammarParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

GrammarParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::ProgramContext::EOF() {
  return getToken(GrammarParser::EOF, 0);
}

std::vector<GrammarParser::FunDeclContext *> GrammarParser::ProgramContext::funDecl() {
  return getRuleContexts<GrammarParser::FunDeclContext>();
}

GrammarParser::FunDeclContext* GrammarParser::ProgramContext::funDecl(size_t i) {
  return getRuleContext<GrammarParser::FunDeclContext>(i);
}


size_t GrammarParser::ProgramContext::getRuleIndex() const {
  return GrammarParser::RuleProgram;
}

void GrammarParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void GrammarParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any GrammarParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::ProgramContext* GrammarParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, GrammarParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(26);
      funDecl();
      setState(29); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::T__0);
    setState(31);
    match(GrammarParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunDeclContext ------------------------------------------------------------------

GrammarParser::FunDeclContext::FunDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GrammarParser::FunDeclContext::ID() {
  return getTokens(GrammarParser::ID);
}

tree::TerminalNode* GrammarParser::FunDeclContext::ID(size_t i) {
  return getToken(GrammarParser::ID, i);
}

tree::TerminalNode* GrammarParser::FunDeclContext::NUM() {
  return getToken(GrammarParser::NUM, 0);
}

tree::TerminalNode* GrammarParser::FunDeclContext::VOID() {
  return getToken(GrammarParser::VOID, 0);
}

std::vector<GrammarParser::LineContext *> GrammarParser::FunDeclContext::line() {
  return getRuleContexts<GrammarParser::LineContext>();
}

GrammarParser::LineContext* GrammarParser::FunDeclContext::line(size_t i) {
  return getRuleContext<GrammarParser::LineContext>(i);
}


size_t GrammarParser::FunDeclContext::getRuleIndex() const {
  return GrammarParser::RuleFunDecl;
}

void GrammarParser::FunDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunDecl(this);
}

void GrammarParser::FunDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunDecl(this);
}


std::any GrammarParser::FunDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitFunDecl(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::FunDeclContext* GrammarParser::funDecl() {
  FunDeclContext *_localctx = _tracker.createInstance<FunDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, GrammarParser::RuleFunDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    match(GrammarParser::T__0);
    setState(34);
    match(GrammarParser::ID);
    setState(35);
    match(GrammarParser::T__1);
    setState(39);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::ID) {
      setState(36);
      match(GrammarParser::ID);
      setState(41);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(42);
    match(GrammarParser::T__2);
    setState(43);
    match(GrammarParser::T__3);
    setState(44);
    _la = _input->LA(1);
    if (!(_la == GrammarParser::NUM

    || _la == GrammarParser::VOID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(45);
    match(GrammarParser::T__4);
    setState(46);
    match(GrammarParser::T__5);
    setState(48); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(47);
      line();
      setState(50); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8118784) != 0));
    setState(52);
    match(GrammarParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

GrammarParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::ExprContext* GrammarParser::LineContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}

GrammarParser::AssignContext* GrammarParser::LineContext::assign() {
  return getRuleContext<GrammarParser::AssignContext>(0);
}

GrammarParser::CreateContext* GrammarParser::LineContext::create() {
  return getRuleContext<GrammarParser::CreateContext>(0);
}

GrammarParser::ReturnExprContext* GrammarParser::LineContext::returnExpr() {
  return getRuleContext<GrammarParser::ReturnExprContext>(0);
}

GrammarParser::ForExprContext* GrammarParser::LineContext::forExpr() {
  return getRuleContext<GrammarParser::ForExprContext>(0);
}

GrammarParser::IfExprContext* GrammarParser::LineContext::ifExpr() {
  return getRuleContext<GrammarParser::IfExprContext>(0);
}

GrammarParser::WhileExprContext* GrammarParser::LineContext::whileExpr() {
  return getRuleContext<GrammarParser::WhileExprContext>(0);
}


size_t GrammarParser::LineContext::getRuleIndex() const {
  return GrammarParser::RuleLine;
}

void GrammarParser::LineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine(this);
}

void GrammarParser::LineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine(this);
}


std::any GrammarParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::LineContext* GrammarParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 4, GrammarParser::RuleLine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(65);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::T__14:
      case GrammarParser::T__15:
      case GrammarParser::NUM:
      case GrammarParser::TERN_OP:
      case GrammarParser::BIN_OP:
      case GrammarParser::ID:
      case GrammarParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(58);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          setState(54);
          expr();
          break;
        }

        case 2: {
          setState(55);
          assign();
          break;
        }

        case 3: {
          setState(56);
          create();
          break;
        }

        case 4: {
          setState(57);
          returnExpr();
          break;
        }

        default:
          break;
        }
        setState(60);
        match(GrammarParser::T__7);
        break;
      }

      case GrammarParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(62);
        forExpr();
        break;
      }

      case GrammarParser::T__12: {
        enterOuterAlt(_localctx, 3);
        setState(63);
        ifExpr();
        break;
      }

      case GrammarParser::T__13: {
        enterOuterAlt(_localctx, 4);
        setState(64);
        whileExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForExprContext ------------------------------------------------------------------

GrammarParser::ForExprContext::ForExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GrammarParser::ForExprContext::ID() {
  return getTokens(GrammarParser::ID);
}

tree::TerminalNode* GrammarParser::ForExprContext::ID(size_t i) {
  return getToken(GrammarParser::ID, i);
}

std::vector<GrammarParser::ExprContext *> GrammarParser::ForExprContext::expr() {
  return getRuleContexts<GrammarParser::ExprContext>();
}

GrammarParser::ExprContext* GrammarParser::ForExprContext::expr(size_t i) {
  return getRuleContext<GrammarParser::ExprContext>(i);
}

std::vector<GrammarParser::LineContext *> GrammarParser::ForExprContext::line() {
  return getRuleContexts<GrammarParser::LineContext>();
}

GrammarParser::LineContext* GrammarParser::ForExprContext::line(size_t i) {
  return getRuleContext<GrammarParser::LineContext>(i);
}


size_t GrammarParser::ForExprContext::getRuleIndex() const {
  return GrammarParser::RuleForExpr;
}

void GrammarParser::ForExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForExpr(this);
}

void GrammarParser::ForExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForExpr(this);
}


std::any GrammarParser::ForExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitForExpr(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::ForExprContext* GrammarParser::forExpr() {
  ForExprContext *_localctx = _tracker.createInstance<ForExprContext>(_ctx, getState());
  enterRule(_localctx, 6, GrammarParser::RuleForExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    match(GrammarParser::T__8);
    setState(76); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(68);
      match(GrammarParser::T__9);
      setState(69);
      match(GrammarParser::ID);
      setState(70);
      match(GrammarParser::T__10);
      setState(71);
      expr();
      setState(72);
      match(GrammarParser::T__10);
      setState(73);
      expr();
      setState(74);
      match(GrammarParser::T__11);
      setState(78); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::T__9);
    setState(80);
    match(GrammarParser::T__5);
    setState(82); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(81);
      line();
      setState(84); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8118784) != 0));
    setState(86);
    match(GrammarParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfExprContext ------------------------------------------------------------------

GrammarParser::IfExprContext::IfExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::ExprContext* GrammarParser::IfExprContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}

std::vector<GrammarParser::LineContext *> GrammarParser::IfExprContext::line() {
  return getRuleContexts<GrammarParser::LineContext>();
}

GrammarParser::LineContext* GrammarParser::IfExprContext::line(size_t i) {
  return getRuleContext<GrammarParser::LineContext>(i);
}


size_t GrammarParser::IfExprContext::getRuleIndex() const {
  return GrammarParser::RuleIfExpr;
}

void GrammarParser::IfExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfExpr(this);
}

void GrammarParser::IfExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfExpr(this);
}


std::any GrammarParser::IfExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitIfExpr(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::IfExprContext* GrammarParser::ifExpr() {
  IfExprContext *_localctx = _tracker.createInstance<IfExprContext>(_ctx, getState());
  enterRule(_localctx, 8, GrammarParser::RuleIfExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(GrammarParser::T__12);
    setState(89);
    match(GrammarParser::T__9);
    setState(90);
    expr();
    setState(91);
    match(GrammarParser::T__11);
    setState(92);
    match(GrammarParser::T__5);
    setState(94); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(93);
      line();
      setState(96); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8118784) != 0));
    setState(98);
    match(GrammarParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileExprContext ------------------------------------------------------------------

GrammarParser::WhileExprContext::WhileExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::ExprContext* GrammarParser::WhileExprContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}

std::vector<GrammarParser::LineContext *> GrammarParser::WhileExprContext::line() {
  return getRuleContexts<GrammarParser::LineContext>();
}

GrammarParser::LineContext* GrammarParser::WhileExprContext::line(size_t i) {
  return getRuleContext<GrammarParser::LineContext>(i);
}


size_t GrammarParser::WhileExprContext::getRuleIndex() const {
  return GrammarParser::RuleWhileExpr;
}

void GrammarParser::WhileExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileExpr(this);
}

void GrammarParser::WhileExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileExpr(this);
}


std::any GrammarParser::WhileExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitWhileExpr(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::WhileExprContext* GrammarParser::whileExpr() {
  WhileExprContext *_localctx = _tracker.createInstance<WhileExprContext>(_ctx, getState());
  enterRule(_localctx, 10, GrammarParser::RuleWhileExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(GrammarParser::T__13);
    setState(101);
    match(GrammarParser::T__9);
    setState(102);
    expr();
    setState(103);
    match(GrammarParser::T__11);
    setState(104);
    match(GrammarParser::T__5);
    setState(106); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(105);
      line();
      setState(108); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8118784) != 0));
    setState(110);
    match(GrammarParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

GrammarParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::ExprContext::ID() {
  return getToken(GrammarParser::ID, 0);
}

GrammarParser::FunParamsContext* GrammarParser::ExprContext::funParams() {
  return getRuleContext<GrammarParser::FunParamsContext>(0);
}

std::vector<GrammarParser::ExprContext *> GrammarParser::ExprContext::expr() {
  return getRuleContexts<GrammarParser::ExprContext>();
}

GrammarParser::ExprContext* GrammarParser::ExprContext::expr(size_t i) {
  return getRuleContext<GrammarParser::ExprContext>(i);
}

tree::TerminalNode* GrammarParser::ExprContext::TERN_OP() {
  return getToken(GrammarParser::TERN_OP, 0);
}

tree::TerminalNode* GrammarParser::ExprContext::BIN_OP() {
  return getToken(GrammarParser::BIN_OP, 0);
}

tree::TerminalNode* GrammarParser::ExprContext::INT() {
  return getToken(GrammarParser::INT, 0);
}


size_t GrammarParser::ExprContext::getRuleIndex() const {
  return GrammarParser::RuleExpr;
}

void GrammarParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void GrammarParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any GrammarParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::ExprContext* GrammarParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 12, GrammarParser::RuleExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(145);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(112);
      match(GrammarParser::ID);
      setState(113);
      funParams();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(114);
      match(GrammarParser::ID);
      setState(126);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GrammarParser::T__9) {
        setState(115);
        match(GrammarParser::T__9);
        setState(116);
        expr();
        setState(121);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GrammarParser::T__10) {
          setState(117);
          match(GrammarParser::T__10);
          setState(118);
          expr();
          setState(123);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(124);
        match(GrammarParser::T__11);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(128);
      match(GrammarParser::TERN_OP);
      setState(129);
      match(GrammarParser::T__1);
      setState(130);
      expr();
      setState(131);
      match(GrammarParser::T__10);
      setState(132);
      expr();
      setState(133);
      match(GrammarParser::T__10);
      setState(134);
      expr();
      setState(135);
      match(GrammarParser::T__2);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(137);
      match(GrammarParser::BIN_OP);
      setState(138);
      match(GrammarParser::T__1);
      setState(139);
      expr();
      setState(140);
      match(GrammarParser::T__10);
      setState(141);
      expr();
      setState(142);
      match(GrammarParser::T__2);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(144);
      match(GrammarParser::INT);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunParamsContext ------------------------------------------------------------------

GrammarParser::FunParamsContext::FunParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GrammarParser::ExprContext *> GrammarParser::FunParamsContext::expr() {
  return getRuleContexts<GrammarParser::ExprContext>();
}

GrammarParser::ExprContext* GrammarParser::FunParamsContext::expr(size_t i) {
  return getRuleContext<GrammarParser::ExprContext>(i);
}


size_t GrammarParser::FunParamsContext::getRuleIndex() const {
  return GrammarParser::RuleFunParams;
}

void GrammarParser::FunParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunParams(this);
}

void GrammarParser::FunParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunParams(this);
}


std::any GrammarParser::FunParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitFunParams(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::FunParamsContext* GrammarParser::funParams() {
  FunParamsContext *_localctx = _tracker.createInstance<FunParamsContext>(_ctx, getState());
  enterRule(_localctx, 14, GrammarParser::RuleFunParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(GrammarParser::T__1);
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7864320) != 0)) {
      setState(148);
      expr();
      setState(153);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::T__10) {
        setState(149);
        match(GrammarParser::T__10);
        setState(150);
        expr();
        setState(155);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(158);
    match(GrammarParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

GrammarParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::AssignContext::ID() {
  return getToken(GrammarParser::ID, 0);
}

std::vector<GrammarParser::ExprContext *> GrammarParser::AssignContext::expr() {
  return getRuleContexts<GrammarParser::ExprContext>();
}

GrammarParser::ExprContext* GrammarParser::AssignContext::expr(size_t i) {
  return getRuleContext<GrammarParser::ExprContext>(i);
}


size_t GrammarParser::AssignContext::getRuleIndex() const {
  return GrammarParser::RuleAssign;
}

void GrammarParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void GrammarParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}


std::any GrammarParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::AssignContext* GrammarParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 16, GrammarParser::RuleAssign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    match(GrammarParser::ID);
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::T__9) {
      setState(161);
      match(GrammarParser::T__9);
      setState(162);
      expr();
      setState(167);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::T__10) {
        setState(163);
        match(GrammarParser::T__10);
        setState(164);
        expr();
        setState(169);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(170);
      match(GrammarParser::T__11);
    }
    setState(174);
    match(GrammarParser::T__4);
    setState(175);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateContext ------------------------------------------------------------------

GrammarParser::CreateContext::CreateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::VarDeclContext* GrammarParser::CreateContext::varDecl() {
  return getRuleContext<GrammarParser::VarDeclContext>(0);
}

GrammarParser::ArrDeclContext* GrammarParser::CreateContext::arrDecl() {
  return getRuleContext<GrammarParser::ArrDeclContext>(0);
}


size_t GrammarParser::CreateContext::getRuleIndex() const {
  return GrammarParser::RuleCreate;
}

void GrammarParser::CreateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate(this);
}

void GrammarParser::CreateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate(this);
}


std::any GrammarParser::CreateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitCreate(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::CreateContext* GrammarParser::create() {
  CreateContext *_localctx = _tracker.createInstance<CreateContext>(_ctx, getState());
  enterRule(_localctx, 18, GrammarParser::RuleCreate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(179);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::NUM: {
        enterOuterAlt(_localctx, 1);
        setState(177);
        varDecl();
        break;
      }

      case GrammarParser::T__14: {
        enterOuterAlt(_localctx, 2);
        setState(178);
        arrDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

GrammarParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::VarDeclContext::NUM() {
  return getToken(GrammarParser::NUM, 0);
}

tree::TerminalNode* GrammarParser::VarDeclContext::ID() {
  return getToken(GrammarParser::ID, 0);
}

GrammarParser::ExprContext* GrammarParser::VarDeclContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}


size_t GrammarParser::VarDeclContext::getRuleIndex() const {
  return GrammarParser::RuleVarDecl;
}

void GrammarParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void GrammarParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


std::any GrammarParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::VarDeclContext* GrammarParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, GrammarParser::RuleVarDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(GrammarParser::NUM);
    setState(182);
    match(GrammarParser::ID);
    setState(183);
    match(GrammarParser::T__4);
    setState(184);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrDeclContext ------------------------------------------------------------------

GrammarParser::ArrDeclContext::ArrDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GrammarParser::ArrDeclContext::INT() {
  return getTokens(GrammarParser::INT);
}

tree::TerminalNode* GrammarParser::ArrDeclContext::INT(size_t i) {
  return getToken(GrammarParser::INT, i);
}

tree::TerminalNode* GrammarParser::ArrDeclContext::ID() {
  return getToken(GrammarParser::ID, 0);
}


size_t GrammarParser::ArrDeclContext::getRuleIndex() const {
  return GrammarParser::RuleArrDecl;
}

void GrammarParser::ArrDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrDecl(this);
}

void GrammarParser::ArrDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrDecl(this);
}


std::any GrammarParser::ArrDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitArrDecl(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::ArrDeclContext* GrammarParser::arrDecl() {
  ArrDeclContext *_localctx = _tracker.createInstance<ArrDeclContext>(_ctx, getState());
  enterRule(_localctx, 22, GrammarParser::RuleArrDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(GrammarParser::T__14);
    setState(187);
    match(GrammarParser::T__9);
    setState(188);
    match(GrammarParser::INT);
    setState(193);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::T__10) {
      setState(189);
      match(GrammarParser::T__10);
      setState(190);
      match(GrammarParser::INT);
      setState(195);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(196);
    match(GrammarParser::T__11);
    setState(197);
    match(GrammarParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnExprContext ------------------------------------------------------------------

GrammarParser::ReturnExprContext::ReturnExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::ExprContext* GrammarParser::ReturnExprContext::expr() {
  return getRuleContext<GrammarParser::ExprContext>(0);
}


size_t GrammarParser::ReturnExprContext::getRuleIndex() const {
  return GrammarParser::RuleReturnExpr;
}

void GrammarParser::ReturnExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnExpr(this);
}

void GrammarParser::ReturnExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnExpr(this);
}


std::any GrammarParser::ReturnExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitReturnExpr(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::ReturnExprContext* GrammarParser::returnExpr() {
  ReturnExprContext *_localctx = _tracker.createInstance<ReturnExprContext>(_ctx, getState());
  enterRule(_localctx, 24, GrammarParser::RuleReturnExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(GrammarParser::T__15);
    setState(201);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7864320) != 0)) {
      setState(200);
      expr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void GrammarParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  grammarParserInitialize();
#else
  ::antlr4::internal::call_once(grammarParserOnceFlag, grammarParserInitialize);
#endif
}
