'use strict';

const routes     = require('./routes/index');
const serverless = require('./node_modules/serverless-http/serverless-http');
const express    = require('./node_modules/express');

const app = express();
app.use(express.urlencoded({ extended: true }));
app.use(express.json());

app.use('/', routes);

module.exports.handler = serverless(app);