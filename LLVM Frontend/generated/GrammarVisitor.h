
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "GrammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by GrammarParser.
 */
class  GrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by GrammarParser.
   */
    virtual std::any visitProgram(GrammarParser::ProgramContext *context) = 0;

    virtual std::any visitFunDecl(GrammarParser::FunDeclContext *context) = 0;

    virtual std::any visitLine(GrammarParser::LineContext *context) = 0;

    virtual std::any visitForExpr(GrammarParser::ForExprContext *context) = 0;

    virtual std::any visitIfExpr(GrammarParser::IfExprContext *context) = 0;

    virtual std::any visitWhileExpr(GrammarParser::WhileExprContext *context) = 0;

    virtual std::any visitExpr(GrammarParser::ExprContext *context) = 0;

    virtual std::any visitFunParams(GrammarParser::FunParamsContext *context) = 0;

    virtual std::any visitAssign(GrammarParser::AssignContext *context) = 0;

    virtual std::any visitCreate(GrammarParser::CreateContext *context) = 0;

    virtual std::any visitVarDecl(GrammarParser::VarDeclContext *context) = 0;

    virtual std::any visitArrDecl(GrammarParser::ArrDeclContext *context) = 0;

    virtual std::any visitReturnExpr(GrammarParser::ReturnExprContext *context) = 0;


};

