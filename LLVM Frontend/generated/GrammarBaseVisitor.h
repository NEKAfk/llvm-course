
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "GrammarVisitor.h"


/**
 * This class provides an empty implementation of GrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  GrammarBaseVisitor : public GrammarVisitor {
public:

  virtual std::any visitProgram(GrammarParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunDecl(GrammarParser::FunDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLine(GrammarParser::LineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForExpr(GrammarParser::ForExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfExpr(GrammarParser::IfExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileExpr(GrammarParser::WhileExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(GrammarParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunParams(GrammarParser::FunParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(GrammarParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreate(GrammarParser::CreateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(GrammarParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrDecl(GrammarParser::ArrDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnExpr(GrammarParser::ReturnExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

